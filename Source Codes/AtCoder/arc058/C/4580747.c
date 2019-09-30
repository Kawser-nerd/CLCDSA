long ans=1,mod=1e9+7,dp[41][1<<17];
no,i,j,k,nxt,M;
main(n,x,y,z)
{
	scanf("%d%d%d%d",&n,&x,&y,&z);
	no=((1|1<<x)<<y|1)<<z-1;
	dp[0][0]=1;
	M=1<<17;
	for(;i++<n;)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<M;k++)
			{
				nxt=(k+k+1<<j)&M-1;
				if(~nxt&no)
				{
					dp[i][nxt]+=dp[i-1][k];
					dp[i][nxt]%=mod;
				}
			}
		}
		ans=ans*10%mod;
	}
	for(;M--;)ans=(ans-dp[n][M]+mod)%mod;
	printf("%d\n",ans);
} ./Main.c:2:1: warning: data definition has no type or storage class
 no,i,j,k,nxt,M;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘no’ [-Wimplicit-int]
./Main.c:2:4: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 no,i,j,k,nxt,M;
    ^
./Main.c:2:6: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 no,i,j,k,nxt,M;
      ^
./Main.c:2:8: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 no,i,j,k,nxt,M;
        ^
./Main.c:2:10: warning: type defaults to ‘int’ in declaration of ‘nxt’ [-Wimplicit-int]
 no,i,j,k,nxt,M;
          ^
./Main.c:2:14: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
 no,i,j,k,nxt,M;
              ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n,x,y,z)
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:1: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:1: warni...