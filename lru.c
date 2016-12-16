#include<stdio.h>

int main()
{
	int m,n,in,i,j,k,l,a[100],p[20],s=0,r[100];
	printf("Enter no. of frames : ");
	scanf("%d",&m);
	printf("Enter no. of pages to allocate : ");
	scanf("%d",&n);
	printf("Enter the page references\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
		p[i]=-1;
	for(i=0;i<100;i++)
		r[i]=-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(p[j]==-1)
			{	p[j]=a[i];
				r[a[i]]=i;
				break;
			}
			else if(p[j]==a[i])
			{	r[a[i]]=i;
				break;
			}
		}
		if(j==m)
		{
			s++;
			k=r[p[0]];
			l=0;
			for(j=1;j<m;j++)
				if(r[p[j]]<k)
				{	k=r[p[j]];
					l=j;
				}
			printf("Page %d replaced by %d\n",p[l],a[i]);				
			p[l]=a[i];
			r[p[l]]=i;
		}
		/*for(j=0;j<m;j++)
			printf("%d\t",p[j]);
		printf("\n");
	}
	for(j=0;j<8;j++)
		printf("%d\t",r[j]);*/
	}
	printf("No. of replacements : %d\n",s);
}
