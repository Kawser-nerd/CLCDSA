#define M 9999
A[M],N,i;long long S[M],D[M],K,z;main(n){for(scanf("%d%lld",&N,&K);i<N;i++)scanf("%d",A+i),S[i+1]=S[i]+A[i],D[i+1]=1<<29;if(S[N]==K){puts("1");return 0;}for(D[1]=n=1;n<N;n++)for(i=n+1;i;i--)if(z=D[i-1]+A[n]*D[i-1]/S[n]+1,D[i-1]<S[n]&&D[i]>z)D[i]=z;for(;~n;n--)if(D[n]<=K){printf("%d\n",n);return 0;}} ./Main.c:2:1: warning: data definition has no type or storage class
 A[M],N,i;long long S[M],D[M],K,z;main(n){for(scanf("%d%lld",&N,&K);i<N;i++)scanf("%d",A+i),S[i+1]=S[i]+A[i],D[i+1]=1<<29;if(S[N]==K){puts("1");return 0;}for(D[1]=n=1;n<N;n++)for(i=n+1;i;i--)if(z=D[i-1]+A[n]*D[i-1]/S[n]+1,D[i-1]<S[n]&&D[i]>z)D[i]=z;for(;~n;n--)if(D[n]<=K){printf("%d\n",n);return 0;}}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
./Main.c:2:6: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
 A[M],N,i;long long S[M],D[M],K,z;main(n){for(scanf("%d%lld",&N,&K);i<N;i++)scanf("%d",A+i),S[i+1]=S[i]+A[i],D[i+1]=1<<29;if(S[N]==K){puts("1");return 0;}for(D[1]=n=1;n<N;n++)for(i=n+1;i;i--)if(z=D[i-1]+A[n]*D[i-1]/S[n]+1,D[i-1]<S[n]&&D[i]>z)D[i]=z;for(;~n;n--)if(D[n]<=K){printf("%d\n",n);return 0;}}
      ^
./Main.c:2:8: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 A[M],N,i;long long S[M],D[M],K,z;main(n){for(scanf("%d%lld",&N,&K);i<N;i++)scanf("%d"...