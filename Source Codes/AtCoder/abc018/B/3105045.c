char s[999];l,r;main(i){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(i=0;i*2<r-l;i++)s[l+i-1]^=s[r-i-1]^=s[l+i-1]^=s[r-i-1];puts(s);} ./Main.c:1:13: warning: data definition has no type or storage class
 char s[999];l,r;main(i){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(i=0;i*2<r-l;i++)s[l+i-1]^=s[r-i-1]^=s[l+i-1]^=s[r-i-1];puts(s);}
             ^
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘r’ [-Wimplicit-int]
 char s[999];l,r;main(i){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(i=0;i*2<r-l;i++)s[l+i-1]^=s[r-i-1]^=s[l+i-1]^=s[r-i-1];puts(s);}
               ^
./Main.c:1:17: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[999];l,r;main(i){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(i=0;i*2<r-l;i++)s[l+i-1]^=s[r-i-1]^=s[l+i-1]^=s[r-i-1];puts(s);}
                 ^
./Main.c: In function ‘main’:
./Main.c:1:17: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:29: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 char s[999];l,r;main(i){for(scanf("%s%*d",s);~sca...