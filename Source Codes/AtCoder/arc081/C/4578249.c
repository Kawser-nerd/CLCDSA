char s[2<<17];p[2<<17][256];i,j,L;main(m){for(i=L=strlen(gets(s));i--;p[i][s[i]]=m+1)for(m=L,j=97;j<123;j++)m=fmin(m,p[i][j]=p[i+1][j]);for(;++i<L;){for(m=j=97;j<123;j++)m=p[i][j]<p[i][m]?j:m;for(putchar(m);i<L&&s[i]-m;i++);}} ./Main.c:1:15: warning: data definition has no type or storage class
 char s[2<<17];p[2<<17][256];i,j,L;main(m){for(i=L=strlen(gets(s));i--;p[i][s[i]]=m+1)for(m=L,j=97;j<123;j++)m=fmin(m,p[i][j]=p[i+1][j]);for(;++i<L;){for(m=j=97;j<123;j++)m=p[i][j]<p[i][m]?j:m;for(putchar(m);i<L&&s[i]-m;i++);}}
               ^
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:1:29: warning: data definition has no type or storage class
 char s[2<<17];p[2<<17][256];i,j,L;main(m){for(i=L=strlen(gets(s));i--;p[i][s[i]]=m+1)for(m=L,j=97;j<123;j++)m=fmin(m,p[i][j]=p[i+1][j]);for(;++i<L;){for(m=j=97;j<123;j++)m=p[i][j]<p[i][m]?j:m;for(putchar(m);i<L&&s[i]-m;i++);}}
                             ^
./Main.c:1:29: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:31: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 char s[2<<17];p[2<<17][256];i,j,L;main(m){for(i=L=strlen(gets(s));i--;p[i][s[i]]=m+1)for(m=L,j=97;j<123;j++)m=fmin(m,p[i][j...