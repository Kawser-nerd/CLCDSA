#include<stdlib.h>
int H,W,K;
char s[502][502];
main(){
	scanf("%d%d%d%*c",&H,&W,&K);
	for(int y=1;y<=H;++y){
		gets(s[y]+1);
	}
	int ans=0;
	for(int y=K;y<=H+1-K;++y){
		for(int x=K;x<=W+1-K;++x){
			for(int dy=-K+1;dy<K;++dy){
				for(int dx=-K+abs(dy)+1;dx<K-abs(dy);++dx){
					if(s[y+dy][x+dx]=='x'){
						goto a;
					}
				}
			}
			++ans;
			a:;
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
./Main.c:23:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d\n",ans);
  ^
./Main.c:23:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:23:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
/tmp/cctvvVIM.o: In function `main':
Main.c:(.text.startup+0x42): warning: the `gets' function is dangerous and should not be used.