long c[1000][1000],ans,mod=1e9+7;a[1000][1000];
d[5]={0,1,0,-1};
h,w;i,j;
f(x,y){
	if(!c[x][y]){
		c[x][y]=1;
		int r,tx,ty;
		for(r=0;r<4;r++){
			tx=x+d[r],ty=y+d[r+1];
			if(tx>=0&&ty>=0&&tx<h&&ty<w&&a[tx][ty]>a[x][y])c[x][y]+=f(tx,ty);
		}
	}
	return c[x][y]%=mod;
}
main(){
	scanf("%d%d",&h,&w);
	for(i=0;i<h;i++)for(j=0;j<w;j++)scanf("%d",a[i]+j);
	for(i=0;i<h;i++)for(j=0;j<w;j++)ans+=f(i,j);
	printf("%d",ans%mod);
} ./Main.c:1:34: warning: data definition has no type or storage class
 long c[1000][1000],ans,mod=1e9+7;a[1000][1000];
                                  ^
./Main.c:1:34: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:2:1: warning: data definition has no type or storage class
 d[5]={0,1,0,-1};
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:3:1: warning: data definition has no type or storage class
 h,w;i,j;
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘h’ [-Wimplicit-int]
./Main.c:3:3: warning: type defaults to ‘int’ in declaration of ‘w’ [-Wimplicit-int]
 h,w;i,j;
   ^
./Main.c:3:5: warning: data definition has no type or storage class
 h,w;i,j;
     ^
./Main.c:3:5: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:3:7: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 h,w;i,j;
       ^
./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit...