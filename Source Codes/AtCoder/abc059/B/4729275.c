char s[999];i;b;main(a){for(gets(s);(a=getchar())>10;b=a>9?:b?b:a)a-=s[i++];puts(s[i]||b<0?"GREATER":b?"LESS":"EQUAL");} ./Main.c:1:13: warning: data definition has no type or storage class
 char s[999];i;b;main(a){for(gets(s);(a=getchar())>10;b=a>9?:b?b:a)a-=s[i++];puts(s[i]||b<0?"GREATER":b?"LESS":"EQUAL");}
             ^
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:15: warning: data definition has no type or storage class
 char s[999];i;b;main(a){for(gets(s);(a=getchar())>10;b=a>9?:b?b:a)a-=s[i++];puts(s[i]||b<0?"GREATER":b?"LESS":"EQUAL");}
               ^
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:17: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[999];i;b;main(a){for(gets(s);(a=getchar())>10;b=a>9?:b?b:a)a-=s[i++];puts(s[i]||b<0?"GREATER":b?"LESS":"EQUAL");}
                 ^
./Main.c: In function ‘main’:
./Main.c:1:17: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:29: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 char s[999];i;b;main(a){fo...