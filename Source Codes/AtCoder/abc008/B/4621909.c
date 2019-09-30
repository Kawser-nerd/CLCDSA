char s[52][51];n[52];i;k;m;main(j){for(scanf("%*d");~scanf("%s",s[++i]);)for(j=0;strcmp(s[++j],s[i])?:++n[j]>m&&(m=n[j],k=j,0););puts(s[k]);} ./Main.c:1:16: warning: data definition has no type or storage class
 char s[52][51];n[52];i;k;m;main(j){for(scanf("%*d");~scanf("%s",s[++i]);)for(j=0;strcmp(s[++j],s[i])?:++n[j]>m&&(m=n[j],k=j,0););puts(s[k]);}
                ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:22: warning: data definition has no type or storage class
 char s[52][51];n[52];i;k;m;main(j){for(scanf("%*d");~scanf("%s",s[++i]);)for(j=0;strcmp(s[++j],s[i])?:++n[j]>m&&(m=n[j],k=j,0););puts(s[k]);}
                      ^
./Main.c:1:22: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:24: warning: data definition has no type or storage class
 char s[52][51];n[52];i;k;m;main(j){for(scanf("%*d");~scanf("%s",s[++i]);)for(j=0;strcmp(s[++j],s[i])?:++n[j]>m&&(m=n[j],k=j,0););puts(s[k]);}
                        ^
./Main.c:1:24: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
./Main.c:1:26: warning: data definition has no type or storage...