char s[999][99],*a;i;j;k;main(l,n,m){for(scanf("%d%d ",&n,&m);gets(s[j++]););for(;l&&i<=n-m;++i)for(j=0;l&&j<=n-m;++j)for(l=0,k=0;k<m;)a=&s[i+k][j],l|=a-strstr(a,s[n+k++]);puts(l?"No":"Yes");} ./Main.c:1:20: warning: data definition has no type or storage class
 char s[999][99],*a;i;j;k;main(l,n,m){for(scanf("%d%d ",&n,&m);gets(s[j++]););for(;l&&i<=n-m;++i)for(j=0;l&&j<=n-m;++j)for(l=0,k=0;k<m;)a=&s[i+k][j],l|=a-strstr(a,s[n+k++]);puts(l?"No":"Yes");}
                    ^
./Main.c:1:20: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:22: warning: data definition has no type or storage class
 char s[999][99],*a;i;j;k;main(l,n,m){for(scanf("%d%d ",&n,&m);gets(s[j++]););for(;l&&i<=n-m;++i)for(j=0;l&&j<=n-m;++j)for(l=0,k=0;k<m;)a=&s[i+k][j],l|=a-strstr(a,s[n+k++]);puts(l?"No":"Yes");}
                      ^
./Main.c:1:22: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:1:24: warning: data definition has no type or storage class
 char s[999][99],*a;i;j;k;main(l,n,m){for(scanf("%d%d ",&n,&m);gets(s[j++]););for(;l&&i<=n-m;++i)for(j=0;l&&j<=n-m;++j)for(l=0,k=0;k<m;)a=&s[i+k][j],l|=a-strstr(a,s[n+k++]);puts(l?"No":"Yes");}
                 ...