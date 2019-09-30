#define D(i,a,b)for(int i=a;i>=b;--i)
f[2005],n,k,M=1e9+7;main(){scanf("%d%d",&n,&k);f[n+1]=1;D(i,n,n-k+1)D(j,n,1)f[j]=j>i?0:(f[j]+f[j+1])%M;D(i,n-k,2)f[1]=f[1]*2%M;printf("%d\n",f[1]);} ./Main.c:2:1: warning: data definition has no type or storage class
 f[2005],n,k,M=1e9+7;main(){scanf("%d%d",&n,&k);f[n+1]=1;D(i,n,n-k+1)D(j,n,1)f[j]=j>i?0:(f[j]+f[j+1])%M;D(i,n-k,2)f[1]=f[1]*2%M;printf("%d\n",f[1]);}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
 f[2005],n,k,M=1e9+7;main(){scanf("%d%d",&n,&k);f[n+1]=1;D(i,n,n-k+1)D(j,n,1)f[j]=j>i?0:(f[j]+f[j+1])%M;D(i,n-k,2)f[1]=f[1]*2%M;printf("%d\n",f[1]);}
         ^
./Main.c:2:11: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 f[2005],n,k,M=1e9+7;main(){scanf("%d%d",&n,&k);f[n+1]=1;D(i,n,n-k+1)D(j,n,1)f[j]=j>i?0:(f[j]+f[j+1])%M;D(i,n-k,2)f[1]=f[1]*2%M;printf("%d\n",f[1]);}
           ^
./Main.c:2:13: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
 f[2005],n,k,M=1e9+7;main(){scanf("%d%d",&n,&k);f[n+1]=1;D(i,n,n-k+1)D(j,n,1)f[j]=j>i?0:(f[j]+f[j+1])%M;D(i,n-k,2)f[1]=f[1]*2%M;printf("%...