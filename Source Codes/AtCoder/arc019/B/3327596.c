char s[300003];
c,n,i;
main(){
	read(0,s,300001);
	n=strlen(s)-1;
	for(;i<n/2;i++)c+=s[i]!=s[n-i-1];
	printf("%d\n",n*25-(c?c-1?0:2:n%2*25));
} ./Main.c:2:1: warning: data definition has no type or storage class
 c,n,i;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
 c,n,i;
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 c,n,i;
     ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:2: warning: implicit declaration of function ‘read’ [-Wimplicit-function-declaration]
  read(0,s,300001);
  ^
./Main.c:5:4: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  n=strlen(s)-1;
    ^
./Main.c:5:4: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:5:4: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:7:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n",n*25-(c?c-1?0:2:n%2*2...