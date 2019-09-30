#include<stdio.h>
typedef unsigned u;
u AB[11][11],BC[11][11],AC[11][11];
u X[1111],Y[1111],Z[1111],H;
u A[1111],B[1111],C[1111],R,a,b,c;
void F(u x,u y,u z)
{
	u i;
	if(z==c){z=0;++y;}
	if(y==b){y=0;++x;}
	if(x==a)
	{
		if(H>R)for(i=-1,R=H;++i<R;){A[i]=X[i];B[i]=Y[i];C[i]=Z[i];}
		return;
	}
	if(AB[x][y]&&BC[y][z]&&AC[x][z])
	{
		--AB[x][y];--BC[y][z];--AC[x][z];
		X[H]=x;Y[H]=y;Z[H]=z;++H;F(x,y,z+1);--H;
		++AB[x][y];++BC[y][z];++AC[x][z];
	}
	F(x,y,z+1);
	return;
}
int main()
{
	u t=0,T,i,j,r;
	for(scanf("%u",&T);t++<T;)
	{
		scanf("%u%u%u%u",&a,&b,&c,&r);
		printf("Case #%u: ",t);R=0;
		for(i=-1;++i<11;)for(j=-1;++j<11;)AB[i][j]=BC[i][j]=AC[i][j]=r;
		F(0,0,0);
		for(printf("%u\n",R);R--;)printf("%u %u %u\n",A[R]+1,B[R]+1,C[R]+1);
	}
	return 0;
}
