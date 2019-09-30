i,j,x[400],y[400],z[400],s,w;
main(p,q)
{
	for(scanf("%*d%*d%d%d%*d",&p,&q);~scanf("%d%d%d",x+j++,y+j,z+j););
	for(;++i<1<<18;s=s<w?w:s)if(__builtin_popcount(i)==p){
		int S[20]={};
		for(j=0;j<400;j++)S[y[j]]+=i&1<<x[j]-1?z[j]:0;
		for(w=j=qsort(S,20,4,"\x8b\6+\7\xc3");j<q;)w+=S[j++];
	}
	printf("%d\n",s);
} ./Main.c:1:1: warning: data definition has no type or storage class
 i,j,x[400],y[400],z[400],s,w;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 i,j,x[400],y[400],z[400],s,w;
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 i,j,x[400],y[400],z[400],s,w;
     ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 i,j,x[400],y[400],z[400],s,w;
            ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘z’ [-Wimplicit-int]
 i,j,x[400],y[400],z[400],s,w;
                   ^
./Main.c:1:26: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 i,j,x[400],y[400],z[400],s,w;
                          ^
./Main.c:1:28: warning: type defaults to ‘int’ in declaration of ‘w’ [-Wimplicit-int]
 i,j,x[400],y[400],z[400],s,w;
                            ^
./Main.c:2:1: warning: re...