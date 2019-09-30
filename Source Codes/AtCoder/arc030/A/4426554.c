int main(){int a,b;scanf("%d%d",&a,&b);puts((a/2>=b)?"YES":"NO");return 0;} ./Main.c: In function ‘main’:
./Main.c:1:20: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 int main(){int a,b;scanf("%d%d",&a,&b);puts((a/2>=b)?"YES":"NO");return 0;}
                    ^
./Main.c:1:20: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:20: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:40: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 int main(){int a,b;scanf("%d%d",&a,&b);puts((a/2>=b)?"YES":"NO");return 0;}
                                        ^