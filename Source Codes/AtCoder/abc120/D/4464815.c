long t,A[1<<17],s[1<<17],p[1<<17];
g(u){return p[u]-u?p[u]=g(p[u]):u;}
f(j,a,b){
	if(~scanf("%d%d",&a,&b)){
		f(j-1);
		A[j]=t;
		a=g(a);b=g(b);
		if(a-b)t-=s[a]*s[b],s[p[a]=b]+=s[a];
	}
}
main(n,m){
	for(scanf("%d%d",&n,&m);n;t+=--n)s[p[n]=n]=1;
	for(f(m);m;)printf("%ld\n",A[m--]);
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 g(u){return p[u]-u?p[u]=g(p[u]):u;}
 ^
./Main.c: In function ‘g’:
./Main.c:2:1: warning: type of ‘u’ defaults to ‘int’ [-Wimplicit-int]
./Main.c: At top level:
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 f(j,a,b){
 ^
./Main.c: In function ‘f’:
./Main.c:3:1: warning: type of ‘j’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  if(~scanf("%d%d",&a,&b)){
      ^
./Main.c:4:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c: At top level:
./Main.c:11:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n,m){
 ^
./Main.c: In function ‘main’:
./Main.c:11:1: warning: type of ‘n’ ...