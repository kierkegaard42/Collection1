#include<stdio.h>

int main()
{
	int m,n,in,i,j,k,l,a[100],p[20],s=0,t;
	printf("Enter no. of frames : ");
	scanf("%d",&m);
	printf("Enter no. of pages to allocate : ");
	scanf("%d",&n);
	printf("Enter the page references\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
		p[i]=-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(p[j]==-1)
			{	p[j]=a[i];
				break;
			}
			else if(p[j]==a[i])
				break;
		}
		if(j==m)
		{
			s++;
			k=0;
			t=0;
			for(j=0;j<m;j++)
			{	for(l=i+1;l<n;l++)
					if(a[l]==p[j])
					{	if(l>k)
						{	k=l;
							t=j;
						}
						break;
					}
				if(l==n)
				{	t=j;
					break;
				}
			}
			printf("Page %d replaced by %d\n",p[t],a[i]);
			p[t]=a[i];
		}
		/*for(j=0;j<m;j++)
			printf("%d\t",p[j]);
		printf("\n");*/
	}
	printf("No. of replacements : %d\n",s);
}
