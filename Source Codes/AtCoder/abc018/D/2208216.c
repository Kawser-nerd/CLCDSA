f(int*a,int*b){return*a-*b;}
p,q,r,i,j,x[400],y[400],z[400],s,w;
main(n,m)
{
	for(scanf("%d%d%d%d%d",&n,&m,&p,&q,&r);~scanf("%d%d%d",x+j,y+j,z+j);y[j++]--)x[j]--;
	for(;i<1<<n;i++)if(__builtin_popcount(i)==p){
		int S[20]={};
		for(j=0;j<r;j++)S[y[j]]+=i&1<<x[j]?z[j]:0;
		qsort(S,m,4,f);
		for(w=j=0;j<q;j++)w+=S[m-j-1];
		s=s<w?w:s;
	}
	printf("%d\n",s);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 f(int*a,int*b){return*a-*b;}
 ^
./Main.c:2:1: warning: data definition has no type or storage class
 p,q,r,i,j,x[400],y[400],z[400],s,w;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘q’ [-Wimplicit-int]
 p,q,r,i,j,x[400],y[400],z[400],s,w;
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘r’ [-Wimplicit-int]
 p,q,r,i,j,x[400],y[400],z[400],s,w;
     ^
./Main.c:2:7: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 p,q,r,i,j,x[400],y[400],z[400],s,w;
       ^
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 p,q,r,i,j,x[400],y[400],z[400],s,w;
         ^
./Main.c:2:11: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 p,q,r,i,j,x[400],y[400],z[400],s,w;
           ^
./Main.c:2:18: warning: type defaults to ‘int’ in declaration of ...