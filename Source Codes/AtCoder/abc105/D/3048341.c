typedef long long W;i,j,N,M;W a[8<<14],v,r;c(W*a,W*b){return*a-*b;}main(){for(scanf("%d%d",&N,&M);~scanf("%lld",++i+a);a[i]=(a[i]+a[i-1])%M);qsort(a+1,N,8,c);for(i=j=0;i++<N;)if(a[i]-a[j]){r=i-j;v+=r*=r-1;j=i;}r=i-j;v+=r*=r-1;printf("%lld\n",v/2);i=0;} ./Main.c:1:21: warning: data definition has no type or storage class
 typedef long long W;i,j,N,M;W a[8<<14],v,r;c(W*a,W*b){return*a-*b;}main(){for(scanf("%d%d",&N,&M);~scanf("%lld",++i+a);a[i]=(a[i]+a[i-1])%M);qsort(a+1,N,8,c);for(i=j=0;i++<N;)if(a[i]-a[j]){r=i-j;v+=r*=r-1;j=i;}r=i-j;v+=r*=r-1;printf("%lld\n",v/2);i=0;}
                     ^
./Main.c:1:21: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:23: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 typedef long long W;i,j,N,M;W a[8<<14],v,r;c(W*a,W*b){return*a-*b;}main(){for(scanf("%d%d",&N,&M);~scanf("%lld",++i+a);a[i]=(a[i]+a[i-1])%M);qsort(a+1,N,8,c);for(i=j=0;i++<N;)if(a[i]-a[j]){r=i-j;v+=r*=r-1;j=i;}r=i-j;v+=r*=r-1;printf("%lld\n",v/2);i=0;}
                       ^
./Main.c:1:25: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
 typedef long long W;i,j,N,M;W a[8<<14],v,r;c(W*a,W*b){return*a-*b;}main(){for(scanf("%d%d",&N,&M);~scanf("%lld",++i+a);a[i]=(a[i]+a[i-1])%M)...