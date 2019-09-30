#include<stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,k,N,M,K;
	scanf("%d",&T);
	for(k=1;k<=T;k++)
	{
		scanf("%d%d%d",&N,&M,&K);
		if(N==1 || N==2 || M==1 || M==2 || K<5)
		{
			printf("Case #%d: %d\n",k,K);
			continue;
		}
		if(N==3 && M==3 && K>4)
		{
			printf("Case #%d: %d\n",k,K-1);
			continue;
		}
		if((N==3 && M==4) || (N==4 && M==3))
		{
			if(K==5)
			printf("Case #%d: %d\n",k,4);
			else if(K==6)
			printf("Case #%d: %d\n",k,5);
			else if(K==7 || K==8)
			printf("Case #%d: %d\n",k,6);
			else
			printf("Case #%d: %d\n",k,K-2);
			continue;
		}
		if((N==3 && M==5) || (N==5 && M==3))
		{
			if(K==5)
			printf("Case #%d: %d\n",k,4);
			else if(K==6)
			printf("Case #%d: %d\n",k,5);
			else if(K==7 || K==8)
			printf("Case #%d: %d\n",k,6);
			else if(K==9)
			printf("Case #%d: %d\n",k,7);
			else if(K==10 || K==11)
			printf("Case #%d: %d\n",k,8);
			else
			printf("Case #%d: %d\n",k,K-3);
			continue;
		}
		if((N==3 && M==6) || (N==6 && M==3))
		{
			if(K==5)
			printf("Case #%d: %d\n",k,4);
			else if(K==6)
			printf("Case #%d: %d\n",k,5);
			else if(K==7 || K==8)
			printf("Case #%d: %d\n",k,6);
			else if(K==9)
			printf("Case #%d: %d\n",k,7);
			else if(K==10 || K==11)
			printf("Case #%d: %d\n",k,8);
			else if(K==12)
			printf("Case #%d: %d\n",k,9);
			else if(K==13 || K==14)
			printf("Case #%d: %d\n",k,10);
			else
			printf("Case #%d: %d\n",k,K-4);
			continue;
		}
		if(N==4 && M==4)
		{
			if(K==5)
			printf("Case #%d: %d\n",k,4);
			else if(K==6)
			printf("Case #%d: %d\n",k,5);
			else if(K==7 || K==8)
			printf("Case #%d: %d\n",k,6);
			else if(K==9 || K==10)
			printf("Case #%d: %d\n",k,7);
			else if(K==11 || K==12)
			printf("Case #%d: %d\n",k,8);
			else
			printf("Case #%d: %d\n",k,K-4);
			continue;
		}
		if((N==4 && M==5) || (N==5 && M==4))
		{
			if(K==5)
			printf("Case #%d: %d\n",k,4);
			else if(K==6)
			printf("Case #%d: %d\n",k,5);
			else if(K==7 || K==8)
			printf("Case #%d: %d\n",k,6);
			else if(K==9 || K==10)
			printf("Case #%d: %d\n",k,7);
			else if(K==11 || K==12)
			printf("Case #%d: %d\n",k,8);
			else if(K==13 || K==14)
			printf("Case #%d: %d\n",k,9);
			else if(K==15 || K==16)
			printf("Case #%d: %d\n",k,10);
			else
			printf("Case #%d: %d\n",k,N-6);
			continue;
		}
	}
	return 0;
}
