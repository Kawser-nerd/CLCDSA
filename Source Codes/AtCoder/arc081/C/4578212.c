char s[2<<17];
dp[2<<17][256];
i,j,L;
main(m){
	gets(s);
	for(i=L=strlen(s);i--;dp[i][s[i]]=m+1)
		for(m=1e9,j=97;j<123;j++)m=fmin(m,dp[i][j]=dp[i+1][j]);
	for(;++i<L;){
		for(m=j=97;j<123;j++)m=dp[i][j]<dp[i][m]?j:m;
		for(putchar(m);i<L&&s[i]-m;i++);
	}
} ./Main.c:2:1: warning: data definition has no type or storage class
 dp[2<<17][256];
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘dp’ [-Wimplicit-int]
./Main.c:3:1: warning: data definition has no type or storage class
 i,j,L;
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:3:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 i,j,L;
   ^
./Main.c:3:5: warning: type defaults to ‘int’ in declaration of ‘L’ [-Wimplicit-int]
 i,j,L;
     ^
./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(m){
 ^
./Main.c: In function ‘main’:
./Main.c:4:1: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:5:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
./Main.c:6:10: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  for(i=L=strlen(s);i--;dp[i][s[i]]=m+1)
          ^
./Main.c:6:10: warning: incompati...