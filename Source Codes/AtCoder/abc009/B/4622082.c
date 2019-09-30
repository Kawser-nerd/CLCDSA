f;s;main(a){for(gets(&a);~scanf("%d",&a);a<s?:a<f?s=a:a>f&&(s=f,f=a));printf("%d\n",s);} ./Main.c:1:1: warning: data definition has no type or storage class
 f;s;main(a){for(gets(&a);~scanf("%d",&a);a<s?:a<f?s=a:a>f&&(s=f,f=a));printf("%d\n",s);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 f;s;main(a){for(gets(&a);~scanf("%d",&a);a<s?:a<f?s=a:a>f&&(s=f,f=a));printf("%d\n",s);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 f;s;main(a){for(gets(&a);~scanf("%d",&a);a<s?:a<f?s=a:a>f&&(s=f,f=a));printf("%d\n",s);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:17: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 f;s;main(a){for(gets(&a);~scanf("%d",&a);a<s?:a<f?s=a:a>f&&(s=f,f=a));printf("%d\n",s);}
                 ^
./Main.c:1:27: warning: implicit declaration of function...