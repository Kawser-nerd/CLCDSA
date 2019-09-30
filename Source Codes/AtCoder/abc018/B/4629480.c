char s[999];main(l,r){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(r--,l--;l<r;l++,r--)s[l]^=s[r]^=s[l]^=s[r];puts(s);} ./Main.c:1:13: warning: return type defaults to ‘int’ [-Wimplicit-int]
 char s[999];main(l,r){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(r--,l--;l<r;l++,r--)s[l]^=s[r]^=s[l]^=s[r];puts(s);}
             ^
./Main.c: In function ‘main’:
./Main.c:1:13: warning: type of ‘l’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: type of ‘r’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:27: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 char s[999];main(l,r){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(r--,l--;l<r;l++,r--)s[l]^=s[r]^=s[l]^=s[r];puts(s);}
                           ^
./Main.c:1:27: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:27: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:113: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 char s[999];main(l,r){for(scanf("%s%*d",s);~scanf("%d%d",&l,&r);)for(r--,l--;l<r;l++,r--)s[l]^=s[r]^=s[l]^=s[r];puts(s);}
      ...