dp[2][2][1<<16];*s=dp[0][0],*t=dp[0][1];w;c;f;p=2e4;i;x,y;
main(a)
{
	s[p]=dp[1][0][p]=1;
	do{
		a=getchar();
		if(a-70){
			for(i=0;i<'~~';i++)t[i]=0;
			for(i=1e4;i<3e4;i++)t[i+c]|=s[i],f&&(t[i-c]|=s[i]);
			w=w?y=f%2,s=dp[0][f%2],t=dp[0][-~f%2],0:(x=-~f%2,s=dp[1][f%2],t=dp[1][++f%2],1);
			c=0;
		}
		else c++;
	}while(a-10);
	scanf("%d%d",&a,&c);
	puts(dp[0][x][p+a]&&dp[1][y][p+c]?"Yes":"No");
} ./Main.c:1:1: warning: data definition has no type or storage class
 dp[2][2][1<<16];*s=dp[0][0],*t=dp[0][1];w;c;f;p=2e4;i;x,y;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘dp’ [-Wimplicit-int]
./Main.c:1:17: warning: data definition has no type or storage class
 dp[2][2][1<<16];*s=dp[0][0],*t=dp[0][1];w;c;f;p=2e4;i;x,y;
                 ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 dp[2][2][1<<16];*s=dp[0][0],*t=dp[0][1];w;c;f;p=2e4;i;x,y;
                  ^
./Main.c:1:30: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 dp[2][2][1<<16];*s=dp[0][0],*t=dp[0][1];w;c;f;p=2e4;i;x,y;
                              ^
./Main.c:1:41: warning: data definition has no type or storage class
 dp[2][2][1<<16];*s=dp[0][0],*t=dp[0][1];w;c;f;p=2e4;i;x,y;
                                         ^
./Main.c:1:41: warning: type defaults to ‘int’ in declaration of ‘w’ [-Wimplicit-int]
./Main.c:1:43: warning: data definition has no type ...