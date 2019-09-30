N,K,x[50],y[50];
i,l,r,u,d,k;
long long w,h,z=4.6e18;
main(){
	scanf("%d%d",&N,&K);
	for(i=0;~scanf("%d%d",x+i,y+i);++i);
	for(l=0;l<N;++l)for(r=0;r<N;++r)for(u=0;u<N;++u)for(d=0;d<N;++d){
		w=x[r]-x[l];
		h=y[d]-y[u];
		if(w>0&&h>0){
			k=0;
			for(i=0;i<N;++i){
				k+=x[l]<=x[i]&&x[i]<=x[r]&&y[u]<=y[i]&&y[i]<=y[d];
			}
			if(k>=K&&w*h<z){
				z=w*h;
			}
		}
	}
	printf("%lld",z);
} ./Main.c:1:1: warning: data definition has no type or storage class
 N,K,x[50],y[50];
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘K’ [-Wimplicit-int]
 N,K,x[50],y[50];
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 N,K,x[50],y[50];
     ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 N,K,x[50],y[50];
           ^
./Main.c:2:1: warning: data definition has no type or storage class
 i,l,r,u,d,k;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 i,l,r,u,d,k;
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘r’ [-Wimplicit-int]
 i,l,r,u,d,k;
     ^
./Main.c:2:7: warning: type defaults to ‘int’ in declaration of ‘u’ [-Wimplicit-int]
 i,l,r,u,d,k;
       ^
./Main.c:2:9: warni...