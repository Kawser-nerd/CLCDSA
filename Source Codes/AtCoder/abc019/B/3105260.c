c,s,t;
main(){
  for(;(s=getchar())>10;){
    if(t==s)c++;
    else{if(c)printf("%c%d",t,c);t=s;c=1;}
  }
  printf("%c%d\n",t,c);
} ./Main.c:1:1: warning: data definition has no type or storage class
 c,s,t;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 c,s,t;
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 c,s,t;
     ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:11: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
   for(;(s=getchar())>10;){
           ^
./Main.c:5:15: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     else{if(c)printf("%c%d",t,c);t=s;c=1;}
               ^
./Main.c:5:15: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:15: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:7:3: warning: incompatible implicit declaration of built-in functi...