n,m,b[503][501],a,i;main(j){for(scanf("%d%d",&n,&m);i++<m;)printf("0");puts("");for(i=1;i++<n;puts(""))for(j=0;j<m;printf("%d",a))scanf("\n%c",&a),a+=b[i][j]-48,b[i+1][j-1]-=a,b[i+1][j+1]-=a,b[i+2][j++]-=a;} ./Main.c:1:1: warning: data definition has no type or storage class
 n,m,b[503][501],a,i;main(j){for(scanf("%d%d",&n,&m);i++<m;)printf("0");puts("");for(i=1;i++<n;puts(""))for(j=0;j<m;printf("%d",a))scanf("\n%c",&a),a+=b[i][j]-48,b[i+1][j-1]-=a,b[i+1][j+1]-=a,b[i+2][j++]-=a;}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 n,m,b[503][501],a,i;main(j){for(scanf("%d%d",&n,&m);i++<m;)printf("0");puts("");for(i=1;i++<n;puts(""))for(j=0;j<m;printf("%d",a))scanf("\n%c",&a),a+=b[i][j]-48,b[i+1][j-1]-=a,b[i+1][j+1]-=a,b[i+2][j++]-=a;}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 n,m,b[503][501],a,i;main(j){for(scanf("%d%d",&n,&m);i++<m;)printf("0");puts("");for(i=1;i++<n;puts(""))for(j=0;j<m;printf("%d",a))scanf("\n%c",&a),a+=b[i][j]-48,b[i+1][j-1]-=a,b[i+1][j+1]-=a,b[i+2][j++]-=a;}
     ^
./Main.c:1:17: warning: type defaults to ‘int’ in declarati...