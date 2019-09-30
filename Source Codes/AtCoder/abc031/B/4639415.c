main(l,h,a){scanf("%d%d%*d",&l,&h);for(;~scanf("%d",&a);)printf("%d\n",a>l?a>h?-1:0:l-a);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(l,h,a){scanf("%d%d%*d",&l,&h);for(;~scanf("%d",&a);)printf("%d\n",a>l?a>h?-1:0:l-a);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘l’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘h’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(l,h,a){scanf("%d%d%*d",&l,&h);for(;~scanf("%d",&a);)printf("%d\n",a>l?a>h?-1:0:l-a);}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:58: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(l,h,a){scanf("%d%d%*d",&l,&h);for(;~scanf("%d",&a);)printf("%d\n",a>l?a>h?-1:0:l-a);}
                                                         ...