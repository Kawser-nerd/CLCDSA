int d[101][101];
char S[101][101];
int f(int y,int x){
	if(d[y][x]){
		return d[y][x];
	}
	if(S[y][x]=='#'){
		return d[y][x]=1;
	}
	if(S[y+1][x]=='#'&&S[y][x+1]=='#'&&S[y+1][x+1]=='#'){
		return d[y][x]=-1;
	}
	return d[y][x]=f(y+1,x)<0|f(y,x+1)<0|f(y+1,x+1)<0?1:-1;
}
main(){
	int H,W;
	scanf("%d%d%*c",&H,&W);
	for(int i=0;i<H;++i){
		gets(S[i]);
		S[i][W]='#';
	}
	for(int i=0;i<=W;++i){
		S[H][i]='#';
	}
	puts(f(0,0)>0?"First":"Second");
} ./Main.c:15:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:17:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d%*c",&H,&W);
  ^
./Main.c:17:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:17:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:19:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(S[i]);
   ^
./Main.c:25:2: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  puts(f(0,0)>0?"First":"Second");
  ^
/tmp/ccKzLvaO.o: In function `main':
Main.c:(.text.startup+0x3a): warning: the `gets' function is dangerous and should not be used.