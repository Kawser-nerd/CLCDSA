char s[9999];n;i;j;main(){for(scanf("%d",&n);~scanf("%s",s+n*j++););for(;i-n;i++,puts(""))for(j=n;j--;)putchar(s[n*j+i]);} ./Main.c:1:14: warning: data definition has no type or storage class
 char s[9999];n;i;j;main(){for(scanf("%d",&n);~scanf("%s",s+n*j++););for(;i-n;i++,puts(""))for(j=n;j--;)putchar(s[n*j+i]);}
              ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:16: warning: data definition has no type or storage class
 char s[9999];n;i;j;main(){for(scanf("%d",&n);~scanf("%s",s+n*j++););for(;i-n;i++,puts(""))for(j=n;j--;)putchar(s[n*j+i]);}
                ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:18: warning: data definition has no type or storage class
 char s[9999];n;i;j;main(){for(scanf("%d",&n);~scanf("%s",s+n*j++););for(;i-n;i++,puts(""))for(j=n;j--;)putchar(s[n*j+i]);}
                  ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:1:20: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[9999];n;i;j;main(){for(scanf("%d",&n);~scanf("%s",s+n*...