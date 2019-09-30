n,c[1<<17],a,i,t,s;
main(){
	for(scanf("%*d");~scanf("%d",&a);)c[a]++;
	for(;++i<1<<17;){
		s+=!!c[i];
		while(c[i]>2)c[i]=c[i]/3+c[i]%3;
		t+=c[i]==2;
	}
	printf("%d\n",s-t%2);
} ./Main.c:1:1: warning: data definition has no type or storage class
 n,c[1<<17],a,i,t,s;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 n,c[1<<17],a,i,t,s;
   ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 n,c[1<<17],a,i,t,s;
            ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 n,c[1<<17],a,i,t,s;
              ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 n,c[1<<17],a,i,t,s;
                ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 n,c[1<<17],a,i,t,s;
                  ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%*d");~sca...