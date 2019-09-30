long long min(long long a,long long b){return a<b?a:b;}
char s[12][12];
long long c[12][12][12][12];
int H,W,T,Sy,Sx,Gy,Gx;
main(){
	scanf("%d%d%d%*c",&H,&W,&T);
	for(int y=1;y<=H;++y){
		gets(s[y]+1);
		for(int x=1;x<=W;++x){
			if(s[y][x]=='S'){
				Sy=y;
				Sx=x;
			}else if(s[y][x]=='G'){
				Gy=y;
				Gx=x;
			}
		}
	}
	int ans;
	for(int l=1,r=T;ans=l+r>>1,r-l>1;){
		for(int y=1;y<=H;++y)for(int x=1;x<=W;++x){
			for(int y2=1;y2<=H;++y2)for(int x2=1;x2<=W;++x2){
				c[y2][x2][y][x]=2e9;
			}
			c[y][x][y][x]=0;
			int t=s[y][x]=='#'?ans:1;
			c[y-1][x][y][x]=t;
			c[y][x-1][y][x]=t;
			c[y][x+1][y][x]=t;
			c[y+1][x][y][x]=t;
		}
		for(int ky=1;ky<=H;++ky)for(int kx=1;kx<=W;++kx){
			for(int iy=1;iy<=H;++iy)for(int ix=1;ix<=W;++ix){
				for(int jy=1;jy<=H;++jy)for(int jx=1;jx<=W;++jx){
					c[iy][ix][jy][jx]=min(c[iy][ix][jy][jx],c[iy][ix][ky][kx]+c[ky][kx][jy][jx]);
				}
			}
		}
		if(c[Sy][Sx][Gy][Gx]<=T){
			l=ans;
		}else{
			r=ans;
		}
	}
	printf("%d\n",ans);
} ./Main.c:5:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d%d%*c",&H,&W,&T);
  ^
./Main.c:6:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:8:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(s[y]+1);
   ^
./Main.c:45:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n",ans);
  ^
./Main.c:45:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:45:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
/tmp/cc9hI21B.o: In function `main':
Main.c:(.text.startup+0x4e): warning: the `gets' function is dangerous and should not be used.