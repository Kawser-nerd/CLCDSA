long dp[200][101];x[400],y[400];m;i,j;
main(n,a,b){
	for(scanf("%d%d%d%*d",&n,&a,&b);~scanf("%d%d",x+m,y+m);m+=2)x[m+1]=y[m],y[m+1]=x[m];
	dp[0][a]=1;
	for(;!dp[j++][b];)for(i=0;i<m;i++)dp[j][x[i]]+=dp[j-1][y[i]];
	printf("%d\n",dp[j-1][b]%1000000007);
} ./Main.c:1:19: warning: data definition has no type or storage class
 long dp[200][101];x[400],y[400];m;i,j;
                   ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:1:26: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 long dp[200][101];x[400],y[400];m;i,j;
                          ^
./Main.c:1:33: warning: data definition has no type or storage class
 long dp[200][101];x[400],y[400];m;i,j;
                                 ^
./Main.c:1:33: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
./Main.c:1:35: warning: data definition has no type or storage class
 long dp[200][101];x[400],y[400];m;i,j;
                                   ^
./Main.c:1:35: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:37: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 long dp[200][101];x[400],y[400];m;i,j;
                                     ^
./Main.c:2:1: warning:...