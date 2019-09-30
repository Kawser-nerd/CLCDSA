a;s[99];main(){for(;gets(s);)a+=!!index(s,114);printf("%d\n",a);} ./Main.c:1:1: warning: data definition has no type or storage class
 a;s[99];main(){for(;gets(s);)a+=!!index(s,114);printf("%d\n",a);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 a;s[99];main(){for(;gets(s);)a+=!!index(s,114);printf("%d\n",a);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:9: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a;s[99];main(){for(;gets(s);)a+=!!index(s,114);printf("%d\n",a);}
         ^
./Main.c: In function ‘main’:
./Main.c:1:21: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 a;s[99];main(){for(;gets(s);)a+=!!index(s,114);printf("%d\n",a);}
                     ^
./Main.c:1:35: warning: implicit declaration of function ‘index’ [-Wimplicit-function-declaration]
 a;s[99];main(){for(;gets(s);)a+=!!index(s,114);printf("%d\n",a);}
                                   ^
./Main....