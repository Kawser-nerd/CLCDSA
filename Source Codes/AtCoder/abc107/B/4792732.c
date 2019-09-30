char s[999][999];j;n;a[999];b[999];c;d;main(i){for(;~scanf("%s",s[n]);n++)for(j=0;s[n][j];b[j++]|=c)a[n]|=c=s[n][j]==35;for(;++i<n;d&&puts(""))for(d=0,j=-1;s[i][++j];c&&putchar(s[i][j]))d|=c=a[i]&b[j];} ./Main.c:1:18: warning: data definition has no type or storage class
 char s[999][999];j;n;a[999];b[999];c;d;main(i){for(;~scanf("%s",s[n]);n++)for(j=0;s[n][j];b[j++]|=c)a[n]|=c=s[n][j]==35;for(;++i<n;d&&puts(""))for(d=0,j=-1;s[i][++j];c&&putchar(s[i][j]))d|=c=a[i]&b[j];}
                  ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:1:20: warning: data definition has no type or storage class
 char s[999][999];j;n;a[999];b[999];c;d;main(i){for(;~scanf("%s",s[n]);n++)for(j=0;s[n][j];b[j++]|=c)a[n]|=c=s[n][j]==35;for(;++i<n;d&&puts(""))for(d=0,j=-1;s[i][++j];c&&putchar(s[i][j]))d|=c=a[i]&b[j];}
                    ^
./Main.c:1:20: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:22: warning: data definition has no type or storage class
 char s[999][999];j;n;a[999];b[999];c;d;main(i){for(;~scanf("%s",s[n]);n++)for(j=0;s[n][j];b[j++]|=c)a[n]|=c=s[n][j]==35;for(;++i<n;d&&puts(""))for(d=0,j=-1;s[i][++j];c&&putchar(s[i][j]))d|=c=a[i...