char s[99];l;main(r){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(l--;l<--r;)s[l++]^=s[r]^=s[l]^=s[r];puts(s);} ./Main.c:1:12: warning: data definition has no type or storage class
 char s[99];l;main(r){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(l--;l<--r;)s[l++]^=s[r]^=s[l]^=s[r];puts(s);}
            ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
./Main.c:1:14: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[99];l;main(r){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(l--;l<--r;)s[l++]^=s[r]^=s[l]^=s[r];puts(s);}
              ^
./Main.c: In function ‘main’:
./Main.c:1:14: warning: type of ‘r’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:26: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 char s[99];l;main(r){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(l--;l<--r;)s[l++]^=s[r]^=s[l]^=s[r];puts(s);}
                          ^
./Main.c:1:26: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:26: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:105: warning: implic...