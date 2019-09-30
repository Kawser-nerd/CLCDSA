main(){int a,b,c;scanf("%d%d%d",&a,&b,&c);puts(((a%=b+c)>0&&a<=b)?"Ant":"Bug");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){int a,b,c;scanf("%d%d%d",&a,&b,&c);puts(((a%=b+c)>0&&a<=b)?"Ant":"Bug");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:18: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(){int a,b,c;scanf("%d%d%d",&a,&b,&c);puts(((a%=b+c)>0&&a<=b)?"Ant":"Bug");}
                  ^
./Main.c:1:18: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:18: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:43: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(){int a,b,c;scanf("%d%d%d",&a,&b,&c);puts(((a%=b+c)>0&&a<=b)?"Ant":"Bug");}
                                           ^