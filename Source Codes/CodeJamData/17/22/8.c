#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int T, N, R, O, Y, G, B, V;
	double t, maxt;

	scanf("%d\n", &T);

	for(int i=0; i<T; i++)
	{
		scanf("%d %d %d %d %d %d %d\n", &N, &R, &O, &Y, &G, &B, &V);
		if(R < G  || Y < V  || B < O )
		{
			printf("Case #%d: IMPOSSIBLE\n",i+1);
			continue;
		}
		if(G > 0 && R < G + 1 && R + G < N)
		{
			printf("Case #%d: IMPOSSIBLE\n",i+1);
			continue;
		}
		if(V > 0 && Y < V + 1 && Y + V < N)
		{
			printf("Case #%d: IMPOSSIBLE\n",i+1);
			continue;
		}
		if(O > 0 && B < O + 1 && B + O < N)
		{
			printf("Case #%d: IMPOSSIBLE\n",i+1);
			continue;
		}
		int R1 = R - G;
		int Y1 = Y - V;
		int B1 = B - O;
		if(R1+Y1+B1==0)
		{
			printf("Case #%d: ",i+1);
			char c1, c2;
			int n;
			if(R==0 && Y==0)
			{
				c1='B';
				c2='O';
				n=B;
			}
			else if(B==0 && Y==0)
			{
				c1='R';
				c2='G';
				n=R;
			}
			else if(R==0 && B==0)
			{
				c1='Y';
				c2='V';
				n=Y;
			}
			else
			{
				printf("IMPOSSIBLE\n");
				continue;
			}
			for(int i = 0; i < n; i++)
				printf("%c%c",c1,c2);
			printf("\n");
			continue;
		}
		if(R1+Y1<B1||R1+B1<Y1||Y1+B1<R1)
		{
			printf("Case #%d: IMPOSSIBLE\n",i+1);
			continue;
		}
		int last=0;
		int first=0;
		printf("Case #%d: ", i+1);
		for(int i = 0; i < N; i++)
		{
			int max = -1;
			int best;
			if((last!=1 && R1>max)||(last!=1 && R1==max && first==1))
			{
				max = R1;
				best = 1;
			}
			if((last!=2 && Y1>max)||(last!=2 && Y1==max && first==2))
			{
				max = Y1;
				best = 2;
			}
			if((last!=3 && B1>max)||(last!=3 && B1==max && first==3))
			{
				max = B1;
				best = 3;
			}
			last=best;
			if(i==0)
				first=best;
			if(best==1)
			{
				printf("R");
				while(G>0)
				{
					printf("GR");
					G--;
					i+=2;
				}
				R1--;
			}
			if(best==2)
			{
				printf("Y");
				while(V>0)
				{
					printf("VY");
					V--;
					i+=2;
				}
				Y1--;
			}
			if(best==3)
			{
				printf("B");
				while(O>0)
				{
					printf("OB");
					O--;
					i+=2;
				}
				B1--;
			}
		}
		printf("\n");
		/*
		for (int j = 0; j < N; j++,printf("\n"))
			for(int k=0; k<M; k++)
				printf("%c", A[j][k]);
				*/
	}

}
