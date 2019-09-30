#define f(i)for(i=0;i<k;i++)
#define _[101]
a _,b _,c _ _,d _ _;i,j,l;main(k,m){for(scanf("%d%d",&k,&m);j<2;j++)f(i)c[i+1][i]=-scanf("%d",j?*c+i:a+k-i-1);for(m-=k;m>0;m/=2){if(m&1){f(i)b[i]=a[i],a[i]=0;f(i)f(j)a[i]^=b[j]&c[i][j];}f(i)f(j)d[i][j]=c[i][j],c[i][j]=0;f(i)f(j)f(l)c[i][j]^=d[i][l]&d[l][j];}printf("%u\n",a[m<0?-m:0]);} ./Main.c:2:10: warning: ISO C99 requires whitespace after the macro name
 #define _[101]
          ^
./Main.c:3:1: warning: data definition has no type or storage class
 a _,b _,c _ _,d _ _;i,j,l;main(k,m){for(scanf("%d%d",&k,&m);j<2;j++)f(i)c[i+1][i]=-scanf("%d",j?*c+i:a+k-i-1);for(m-=k;m>0;m/=2){if(m&1){f(i)b[i]=a[i],a[i]=0;f(i)f(j)a[i]^=b[j]&c[i][j];}f(i)f(j)d[i][j]=c[i][j],c[i][j]=0;f(i)f(j)f(l)c[i][j]^=d[i][l]&d[l][j];}printf("%u\n",a[m<0?-m:0]);}
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:3:5: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a _,b _,c _ _,d _ _;i,j,l;main(k,m){for(scanf("%d%d",&k,&m);j<2;j++)f(i)c[i+1][i]=-scanf("%d",j?*c+i:a+k-i-1);for(m-=k;m>0;m/=2){if(m&1){f(i)b[i]=a[i],a[i]=0;f(i)f(j)a[i]^=b[j]&c[i][j];}f(i)f(j)d[i][j]=c[i][j],c[i][j]=0;f(i)f(j)f(l)c[i][j]^=d[i][l]&d[l][j];}printf("%u\n",a[m<0?-m:0]);}
     ^
./Main.c:3:9: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 a _,b _,c _ _...