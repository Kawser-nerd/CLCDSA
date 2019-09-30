main(a){scanf("%d",&a);printf("%02d:%02d:%02d\n",a/3600,a/60%60,a%60);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){scanf("%d",&a);printf("%02d:%02d:%02d\n",a/3600,a/60%60,a%60);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a){scanf("%d",&a);printf("%02d:%02d:%02d\n",a/3600,a/60%60,a%60);}
         ^
./Main.c:1:9: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:9: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:24: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(a){scanf("%d",&a);printf("%02d:%02d:%02d\n",a/3600,a/60%60,a%60);}
                        ^
./Main.c:1:24: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:24: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’