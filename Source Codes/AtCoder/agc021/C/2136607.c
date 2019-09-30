#define z(c)for(i=1;i<c)
n,m,a,b,i;char p[1009][1009];x(i,j){p[i][j]=94;p[i+1][j]=118;b--;}main(j){scanf("%d%d%d%d",&n,&m,&a,&b);z(n+1;)memset(p[i++]+1,46,m);z(n&&b&&m&1;i+=2)x(i,m);b&n&m>2&n>1&&x(n-1,m-2);z(n;i++)for(j=1;j<=m&&b;j++)p[i][j]+p[i+1][j]<99&&x(i,j);z(n+1;i++)for(j=1;j<m&&a;)if(p[i][j++]+p[i][j]<99)p[i][j-1]=60,p[i][j]=62,a--;puts(a|b?"NO":"YES");z(n+1&!a&!b;)puts(p[i++]+1);} ./Main.c:2:1: warning: data definition has no type or storage class
 n,m,a,b,i;char p[1009][1009];x(i,j){p[i][j]=94;p[i+1][j]=118;b--;}main(j){scanf("%d%d%d%d",&n,&m,&a,&b);z(n+1;)memset(p[i++]+1,46,m);z(n&&b&&m&1;i+=2)x(i,m);b&n&m>2&n>1&&x(n-1,m-2);z(n;i++)for(j=1;j<=m&&b;j++)p[i][j]+p[i+1][j]<99&&x(i,j);z(n+1;i++)for(j=1;j<m&&a;)if(p[i][j++]+p[i][j]<99)p[i][j-1]=60,p[i][j]=62,a--;puts(a|b?"NO":"YES");z(n+1&!a&!b;)puts(p[i++]+1);}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 n,m,a,b,i;char p[1009][1009];x(i,j){p[i][j]=94;p[i+1][j]=118;b--;}main(j){scanf("%d%d%d%d",&n,&m,&a,&b);z(n+1;)memset(p[i++]+1,46,m);z(n&&b&&m&1;i+=2)x(i,m);b&n&m>2&n>1&&x(n-1,m-2);z(n;i++)for(j=1;j<=m&&b;j++)p[i][j]+p[i+1][j]<99&&x(i,j);z(n+1;i++)for(j=1;j<m&&a;)if(p[i][j++]+p[i][j]<99)p[i][j-1]=60,p[i][j]=62,a--;puts(a|b?"NO":"YES");z(n+1&!a&!b;)puts(p[i++]+1);}
   ^
./Main.c:2:5: warning: type defaults to ‘i...