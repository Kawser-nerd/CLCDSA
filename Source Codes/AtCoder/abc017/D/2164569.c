int a[1<<17],n,m,f[1<<17],dp[1<<17]={1},l,M=1e9+7,i;
main(c)
{
	for(scanf("%d%d",&n,&m);~scanf("%d",f+i);c=(dp[++i]=c)*2%M)if(++a[f[i]]>1)for(;c=(c-dp[l]+M)%M,a[f[l++]]--<2;);
	printf("%d\n",dp[n]);
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(c)
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:4:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d%d",&n,&m);~scanf("%d",f+i);c=(dp[++i]=c)*2%M)if(++a[f[i]]>1)for(;c=(c-dp[l]+M)%M,a[f[l++]]--<2;);
      ^
./Main.c:4:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n",dp[n]);
  ^
./Main.c:5:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’