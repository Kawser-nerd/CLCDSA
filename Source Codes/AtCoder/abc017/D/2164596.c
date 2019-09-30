a[1<<17],f[1<<17],p[1<<17]={1},l,M=1e9+7,i;main(c){for(gets(f);~scanf("%d",f+i);c=(p[++i]=c)*2%M)if(a[f[i]]++)for(;c=(c-p[l]+M)%M,!--a[f[l++]];);printf("%d\n",p[i]);} ./Main.c:1:1: warning: data definition has no type or storage class
 a[1<<17],f[1<<17],p[1<<17]={1},l,M=1e9+7,i;main(c){for(gets(f);~scanf("%d",f+i);c=(p[++i]=c)*2%M)if(a[f[i]]++)for(;c=(c-p[l]+M)%M,!--a[f[l++]];);printf("%d\n",p[i]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 a[1<<17],f[1<<17],p[1<<17]={1},l,M=1e9+7,i;main(c){for(gets(f);~scanf("%d",f+i);c=(p[++i]=c)*2%M)if(a[f[i]]++)for(;c=(c-p[l]+M)%M,!--a[f[l++]];);printf("%d\n",p[i]);}
          ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
 a[1<<17],f[1<<17],p[1<<17]={1},l,M=1e9+7,i;main(c){for(gets(f);~scanf("%d",f+i);c=(p[++i]=c)*2%M)if(a[f[i]]++)for(;c=(c-p[l]+M)%M,!--a[f[l++]];);printf("%d\n",p[i]);}
                   ^
./Main.c:1:32: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 a[1<<17],f[1<<17],p[1<<17]={1},l,M=1e9+7,i;main(c){for(gets(f);~scanf("%...