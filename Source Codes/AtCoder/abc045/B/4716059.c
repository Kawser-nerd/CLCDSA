char s[3][999],*t;j[3];i;main(a){for(t=s;~scanf("%s",s[i++]););for(++*j;*t;t=&s[a][j[a]++])a=*t-97;putchar(65+a);} ./Main.c:1:19: warning: data definition has no type or storage class
 char s[3][999],*t;j[3];i;main(a){for(t=s;~scanf("%s",s[i++]););for(++*j;*t;t=&s[a][j[a]++])a=*t-97;putchar(65+a);}
                   ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:1:24: warning: data definition has no type or storage class
 char s[3][999],*t;j[3];i;main(a){for(t=s;~scanf("%s",s[i++]););for(++*j;*t;t=&s[a][j[a]++])a=*t-97;putchar(65+a);}
                        ^
./Main.c:1:24: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:26: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[3][999],*t;j[3];i;main(a){for(t=s;~scanf("%s",s[i++]););for(++*j;*t;t=&s[a][j[a]++])a=*t-97;putchar(65+a);}
                          ^
./Main.c: In function ‘main’:
./Main.c:1:26: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:39: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
 char s[3][999],*t;j[3...