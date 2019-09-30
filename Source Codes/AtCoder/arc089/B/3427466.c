w[4444][4444];
n,k;i,j,x,y,c;ans;now;f;
g(u,v){return w[u+k][v+k]-w[u][v+k]-w[u+k][v]+w[u][v];}
main(){
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d%d %c",&x,&y,&c);
		if(c=='B')x+=k;
		x%=2*k,y%=2*k;
		w[x+1+k][y+1+k]++;
	}
	for(i=1;i<=4*k;i++)for(j=1;j<=4*k;j++)w[i][j]+=w[i-1][j]+w[i][j-1]-w[i-1][j-1];
	for(i=0;i<k;i++)for(j=0;j<k;j++){
		now=g(i+k,j+2*k)+g(i+2*k,j+k)+g(i,j+k)+g(i+k,j);
		if(ans<now)ans=now;
		now=g(i+2*k,j+2*k)+g(i,j+2*k)+g(i+k,j+k)+g(i+2*k,j)+g(i,j);
		if(ans<now)ans=now;
	}
	printf("%d\n",ans);
} ./Main.c:1:1: warning: data definition has no type or storage class
 w[4444][4444];
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘w’ [-Wimplicit-int]
./Main.c:2:1: warning: data definition has no type or storage class
 n,k;i,j,x,y,c;ans;now;f;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 n,k;i,j,x,y,c;ans;now;f;
   ^
./Main.c:2:5: warning: data definition has no type or storage class
 n,k;i,j,x,y,c;ans;now;f;
     ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:2:7: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 n,k;i,j,x,y,c;ans;now;f;
       ^
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 n,k;i,j,x,y,c;ans;now;f;
         ^
./Main.c:2:11: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 n,k;i,j,x,y,c;ans;now;f;
       ...