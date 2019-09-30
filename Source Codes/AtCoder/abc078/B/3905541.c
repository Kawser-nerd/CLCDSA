int main(){int x,y,z;scanf("%d%d%d",&x,&y,&z);printf("%lld",(x-z)/(y+z));} ./Main.c: In function ‘main’:
./Main.c:1:22: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 int main(){int x,y,z;scanf("%d%d%d",&x,&y,&z);printf("%lld",(x-z)/(y+z));}
                      ^
./Main.c:1:22: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:22: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:47: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 int main(){int x,y,z;scanf("%d%d%d",&x,&y,&z);printf("%lld",(x-z)/(y+z));}
                                               ^
./Main.c:1:47: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:47: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:1:54: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘int’ [-Wformat=]
 int main(){int x,y,z;scanf("%d%d%d",&x,&y,&z);printf("%lld",(x-z)/(y+z));}
                                       ...