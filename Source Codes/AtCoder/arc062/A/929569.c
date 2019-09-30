long long a,b,x,y,t;
long long m(long long a,long long b){return a>b?a:b;}
long long c(long long a,long long b){return a%b?a/b+1:a/b;}
main(){
	gets(&t);
	for(scanf("%lld%lld",&x,&y);~scanf("%lld%lld",&a,&b);){
		t=m(c(x,a),c(y,b));
		x=a*t;
		y=b*t;
	}
	printf("%lld\n",x+y);
	return 0;
} ./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(&t);
  ^
./Main.c:6:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%lld%lld",&x,&y);~scanf("%lld%lld",&a,&b);){
      ^
./Main.c:6:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:11:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%lld\n",x+y);
  ^
./Main.c:11:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:11:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
/tmp/ccTqKpS5.o: In function `main':
Main.c:(.text.startup+0xc): warning: the `gets' function is dangerous and should not be used.