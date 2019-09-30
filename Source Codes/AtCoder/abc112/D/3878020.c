main(){int n,m;scanf("%d%d",&n,&m);for(int i=m/n;i>=1;i--){if(m%i==0){printf("%lld",i);return 0;}}} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){int n,m;scanf("%d%d",&n,&m);for(int i=m/n;i>=1;i--){if(m%i==0){printf("%lld",i);return 0;}}}
 ^
./Main.c: In function ‘main’:
./Main.c:1:16: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(){int n,m;scanf("%d%d",&n,&m);for(int i=m/n;i>=1;i--){if(m%i==0){printf("%lld",i);return 0;}}}
                ^
./Main.c:1:16: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:16: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:71: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(){int n,m;scanf("%d%d",&n,&m);for(int i=m/n;i>=1;i--){if(m%i==0){printf("%lld",i);return 0;}}}
                                                                       ^
./Main.c:1:71: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:71: note: include ‘<stdio.h>’ or provide a declaration of ‘printf...