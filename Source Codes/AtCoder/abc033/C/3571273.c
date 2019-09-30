c,i,n;char s[1<<17];
main(f){
	n=read(0,s,100000);
	for(;i<n;i++)s[i]=='+'?c+=f,f=1:(f*=s[i]!='0');
	printf("%d\n",c+f);
} ./Main.c:1:1: warning: data definition has no type or storage class
 c,i,n;char s[1<<17];
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 c,i,n;char s[1<<17];
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
 c,i,n;char s[1<<17];
     ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(f){
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘f’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:4: warning: implicit declaration of function ‘read’ [-Wimplicit-function-declaration]
  n=read(0,s,100000);
    ^
./Main.c:5:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n",c+f);
  ^
./Main.c:5:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’