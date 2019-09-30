long dp[200][101];x[500],y[500];j;
main(i,n,a,b){
	for(scanf("%d%d%d%*d",&n,&a,&b);~scanf("%d%d",x+i,y+i);i+=2)x[i+1]=y[i],y[i+1]=x[i];
	for(dp[1][a]=1;!dp[++j][b];)for(i=0;x[++i];)dp[j+1][x[i]]+=dp[j][y[i]];
	printf("%d\n",dp[j][b]%=a=1e9+7);
} ./Main.c:1:19: warning: data definition has no type or storage class
 long dp[200][101];x[500],y[500];j;
                   ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:1:26: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 long dp[200][101];x[500],y[500];j;
                          ^
./Main.c:1:33: warning: data definition has no type or storage class
 long dp[200][101];x[500],y[500];j;
                                 ^
./Main.c:1:33: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i,n,a,b){
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:6: warning: implicit d...