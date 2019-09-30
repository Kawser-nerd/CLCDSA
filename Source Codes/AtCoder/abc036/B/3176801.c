char m[55][55];i,j;main(n){for(scanf("%d\n",&n);gets(m[i++]););for(;j<n;j++,puts(""))for(i=n;i--;)putchar(m[i][j]);} ./Main.c:1:16: warning: data definition has no type or storage class
 char m[55][55];i,j;main(n){for(scanf("%d\n",&n);gets(m[i++]););for(;j<n;j++,puts(""))for(i=n;i--;)putchar(m[i][j]);}
                ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 char m[55][55];i,j;main(n){for(scanf("%d\n",&n);gets(m[i++]););for(;j<n;j++,puts(""))for(i=n;i--;)putchar(m[i][j]);}
                  ^
./Main.c:1:20: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char m[55][55];i,j;main(n){for(scanf("%d\n",&n);gets(m[i++]););for(;j<n;j++,puts(""))for(i=n;i--;)putchar(m[i][j]);}
                    ^
./Main.c: In function ‘main’:
./Main.c:1:20: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:32: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 char m[55][55];i,j;main(n){for(scanf("%d\n",&n);gets(m[i++]););for(;j<n;j++,puts(""))for(i=n;i--;...