#include<stdio.h>
typedef unsigned u;
char R[13][4150],P[13][4150],S[13][4150],Nx[128];
u Cr[13][150],Cp[13][150],Cs[13][150];
void sort(char*X,u l)
{
	if(!l)return;
	sort(X+0,l>>1);
	sort(X+l,l>>1);
	u i,j;
	for(i=-1;++i<l;)
	{
		if(X[i]<X[i+l])return;
		if(X[i]>X[i+l])goto swp;
	}
	return;swp:;
	for(i=-1;++i<l;)
	{j=X[i];X[i]=X[i+l];X[i+l]=j;}
	return;
}
int main()
{
	++Cr[0][(u)(R[0][0]='R')];
	++Cp[0][(u)(P[0][0]='P')];
	++Cs[0][(u)(S[0][0]='S')];
	Nx['R']='S';Nx['S']='P';Nx['P']='R';
	u t=0,T,r,p,s,n,i,j,k;
	for(i=0;++i<13;)
	{
		for(k=1u<<i,j=-1;++j<k;)
		{
			if(j&1)
			{
				R[i][j]=Nx[(u)R[i-1][j>>1]];
				P[i][j]=Nx[(u)P[i-1][j>>1]];
				S[i][j]=Nx[(u)S[i-1][j>>1]];
			}
			else
			{
				R[i][j]=R[i-1][j>>1];
				P[i][j]=P[i-1][j>>1];
				S[i][j]=S[i-1][j>>1];
			}
			++Cr[i][(u)R[i][j]];
			++Cp[i][(u)P[i][j]];
			++Cs[i][(u)S[i][j]];
		}
		sort(R[i],k>>1);
		sort(P[i],k>>1);
		sort(S[i],k>>1);
	}
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%u%u%u%u",&n,&r,&p,&s);
		printf("Case #%u: ",t);
		if(r==Cr[n]['R']&&p==Cr[n]['P']&&s==Cr[n]['S'])
		printf("%s\n",R[n]);
		else if(r==Cp[n]['R']&&p==Cp[n]['P']&&s==Cp[n]['S'])
		printf("%s\n",P[n]);
		else if(r==Cs[n]['R']&&p==Cs[n]['P']&&s==Cs[n]['S'])
		printf("%s\n",S[n]);
		else
		printf("IMPOSSIBLE\n");
	}
	return 0;
}
