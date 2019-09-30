#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c,k;
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&k);
		if(k>c)
		{
			printf("Case #%d: %d\n",++cas,a*b*c);
			for(int i=0;i<a;i++)
			{
				for(int j=0;j<b;j++)
				{
					for(int l=0;l<c;l++)
					{
						printf("%d %d %d\n",i+1,j+1,l+1);
					}
				}
			}
		}
		else{
			printf("Case #%d: %d\n",++cas,a*b*k);
			for(int i=0;i<a;i++)
			{
				for(int j=0;j<b;j++)
				{
					for(int l=0;l<k;l++)
					{
						printf("%d %d %d\n",i+1,j+1,(i+j+l)%c+1);
					}
				}
			}
		}
		
	}
}