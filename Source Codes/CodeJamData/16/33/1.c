#include <stdio.h>
#include <string.h>
#include <malloc.h>
void main()
{
	int cases;
	scanf("%d",&cases);
	int n = 0;
	int i,j,p,s;
	int J,P,S,K;
	int arrj[1001],arrp[1001],arrs[1001];
	while(n<cases)
	{
		n++;
		printf("Case #%d: ",n);
		scanf("%d%d%d%d",&J,&P,&S,&K);
		int min1,min2,min3,min4;
		min1 = J*P*S;
		min2 = J*P*K;
		min3 = J*S*K;
		min4 = P*S*K;
		int min,index;
		if(min1<=min2&&min1<=min3&&min1<=min4)
		{
			printf("%d\n",min1);
			min = 0;
			for(j=0;j<J;j++)
			{
				for(p=0;p<P;p++)
				{
					for(s=0;s<S;s++)
					{
						printf("%d %d %d\n",j+1,p+1,s+1);
					}
				}
			}				
		}
		else if(min2<=min1&&min2<=min3&&min2<=min4)
		{
			printf("%d\n",min2);
			index = 0;
			for(j=0;j<J;j++)
			for(i=0;i<min2/J;i++)
			{
				arrj[index++]=j+1;
			}
			index = 0;
			for(j=0;j<J;j++)
			for(p=0;p<P;p++)
			for(i=0;i<min2/P/J;i++)
			{
				arrp[index++]=p+1;
			}
			for(i=0;i<min2;i++)
			{
				if(J%S==0||P%S==0)
					arrs[i]=((i+(i/S))%S)+1;
				else
					arrs[i]=((i)%S)+1;
			}
			for(i=0;i<min2;i++)
			{
				printf("%d %d %d\n",arrj[i],arrp[i],arrs[i]);
			}
		}
		else if(min3<=min2&&min3<=min1&&min3<=min4)
		{
			printf("%d\n",min3);
			index = 0;
			for(j=0;j<J;j++)
			for(i=0;i<min3/J;i++)
			{
				arrj[index++]=j+1;
			}
			index = 0;
			for(j=0;j<J;j++)
			for(p=0;p<S;p++)
			for(i=0;i<min3/S/J;i++)
			{
				arrs[index++]=p+1;
			}
			for(i=0;i<min3;i++)
			{
				if(S%P==0||J%P==0)
					arrp[i]=((i+(i/P))%P)+1;
				else
					arrp[i]=((i)%P)+1;


			}
			for(i=0;i<min3;i++)
			{
				printf("%d %d %d\n",arrj[i],arrp[i],arrs[i]);
			}
		}
		else if(min4<=min2&&min4<=min3&&min4<=min1)
		{
			printf("%d\n",min4);
			index = 0;
			for(j=0;j<S;j++)
			for(i=0;i<min4/S;i++)
			{
				arrs[index++]=j+1;
			}
			index = 0;
			for(j=0;j<S;j++)
			for(p=0;p<P;p++)
			for(i=0;i<min4/P/S;i++)
			{
				arrp[index++]=p+1;
			}
			for(i=0;i<min4;i++)
			{
				if(S%J==0||P%J==0)
					arrj[i]=((i+(i/J))%J)+1;
				else
					arrj[i]=((i)%J)+1;
			}
			for(i=0;i<min4;i++)
			{
				printf("%d %d %d\n",arrj[i],arrp[i],arrs[i]);
			}
		}
	}
}
