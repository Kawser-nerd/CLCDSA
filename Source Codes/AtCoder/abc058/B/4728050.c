char o[999];i;j;;main(a){for(;j-2;++j)for(i=0;(a=getchar())>10;)o[i++*2+j]=a;puts(o);} ./Main.c:1:13: warning: data definition has no type or storage class
 char o[999];i;j;;main(a){for(;j-2;++j)for(i=0;(a=getchar())>10;)o[i++*2+j]=a;puts(o);}
             ^
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:15: warning: data definition has no type or storage class
 char o[999];i;j;;main(a){for(;j-2;++j)for(i=0;(a=getchar())>10;)o[i++*2+j]=a;puts(o);}
               ^
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:1:18: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char o[999];i;j;;main(a){for(;j-2;++j)for(i=0;(a=getchar())>10;)o[i++*2+j]=a;puts(o);}
                  ^
./Main.c: In function ‘main’:
./Main.c:1:18: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:50: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 char o[999];i;j;;main(a){for(;j-2;++j)for(i=0;(a=getchar())>10;)o[i++*2+j]=a;puts(o);}
                                     ...