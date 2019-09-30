long n,m,i,s=1,c,t;
main(){
	scanf("%ld",&n);
	m=n*2;
	for(i=2;i*i<=n;i++){
		c=1;
		t=1;
		while(n%i<1){
			c+=t*=i;
			n/=i;
		}
		s*=c;
	}
	if(n>1)s*=n+1;
	if(s==m)puts("Perfect");
	else if(s<m)puts("Deficient");
	else puts("Abundant");
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%ld",&n);
  ^
./Main.c:3:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:15:10: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  if(s==m)puts("Perfect");
          ^