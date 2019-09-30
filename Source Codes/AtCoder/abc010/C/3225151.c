#include<stdio.h>

int main(){
	int txa,tya,txb,tyb,T,V,n,i;
	scanf("%d %d %d %d %d %d",&txa,&tya,&txb,&tyb,&T,&V);
	scanf("%d",&n);
	int x[n+1],y[n+1];
	for(i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
	
	for(i=1;i<=n;i++){
		if(sqrt((txa-x[i])*(txa-x[i])+(tya-y[i])*(tya-y[i]))+sqrt((txb-x[i])*(txb-x[i])+(tyb-y[i])*(tyb-y[i]))<=T*V){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
} ./Main.c: In function ‘main’:
./Main.c:11:6: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
   if(sqrt((txa-x[i])*(txa-x[i])+(tya-y[i])*(tya-y[i]))+sqrt((txb-x[i])*(txb-x[i])+(tyb-y[i])*(tyb-y[i]))<=T*V){
      ^
./Main.c:11:6: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:11:6: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d %d",&txa,&tya,&txb,&tyb,&T,&V);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:8:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
                    ^