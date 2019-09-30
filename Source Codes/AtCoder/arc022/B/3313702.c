f,l,M[1<<17],a[1<<17];main(m){for(gets(a);~scanf("%d",a+f);M[a[f]]=m=fmax(m,1-l+f++))for(;M[a[f]];)M[a[l++]]=0;printf("%d\n",m);} ./Main.c:1:1: warning: data definition has no type or storage class
 f,l,M[1<<17],a[1<<17];main(m){for(gets(a);~scanf("%d",a+f);M[a[f]]=m=fmax(m,1-l+f++))for(;M[a[f]];)M[a[l++]]=0;printf("%d\n",m);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 f,l,M[1<<17],a[1<<17];main(m){for(gets(a);~scanf("%d",a+f);M[a[f]]=m=fmax(m,1-l+f++))for(;M[a[f]];)M[a[l++]]=0;printf("%d\n",m);}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
 f,l,M[1<<17],a[1<<17];main(m){for(gets(a);~scanf("%d",a+f);M[a[f]]=m=fmax(m,1-l+f++))for(;M[a[f]];)M[a[l++]]=0;printf("%d\n",m);}
     ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 f,l,M[1<<17],a[1<<17];main(m){for(gets(a);~scanf("%d",a+f);M[a[f]]=m=fmax(m,1-l+f++))for(;M[a[f]];)M[a[l++]]=0;printf("%d\n",m);}
              ^
./Main.c:1:23: warning: return type defaults to ‘int’ [-Wimp...