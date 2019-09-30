int H,W,K;
char s[502][502];
int az[502][502],za[502][502];
main(){
	scanf("%d%d%d%*c",&H,&W,&K);
	for(int y=1;y<=H;++y){
		gets(s[y]+1);
		for(int x=1;x<=W;++x){
			if(s[y][x]=='o'){
				az[y][x]=az[y][x-1]+1;
			}
		}
		for(int x=W;x;--x){
			if(s[y][x]=='o'){
				za[y][x]=za[y][x+1]+1;
			}
		}
	}
	int ans=0;
	for(int y=K;y<=H+1-K;++y){
		for(int x=K;x<=W+1-K;++x){
			for(int d=-K+1;d<K;++d){
				if(az[y+d][x]<K-abs(d)||za[y+d][x]<K-abs(d)){
					--ans;
					break;
				}
			}
			++ans;
		}
	}
	printf("%d\n",ans);
} ./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d%d%*c",&H,&W,&K);
  ^
./Main.c:5:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(s[y]+1);
   ^
./Main.c:23:21: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     if(az[y+d][x]<K-abs(d)||za[y+d][x]<K-abs(d)){
                     ^
./Main.c:31:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n",ans);
  ^
./Main.c:31:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:31:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
/tmp/ccTTZCbv.o: In function ...