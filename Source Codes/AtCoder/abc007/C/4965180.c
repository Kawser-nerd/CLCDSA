#include <stdio.h>

int main(void) {
	int r,c,sy,sx,gy,gx;
	scanf("%d %d %d %d %d %d",&r,&c,&sy,&sx,&gy,&gx);
	char a[50][50];
	for (int i=0;i<r*c;i++){
		if(i%c==0)scanf("%*c%c",&a[i/c][i%c]);
		else scanf("%c",&a[i/c][i%c]);
	}
	sy--;sx--;gy--;gx--;
	
	int b[50][50];
	
	for (int i=0;i<r*c;i++){
		if(a[i/c][i%c]=='#')b[i/c][i%c]=-2;
		else b[i/c][i%c]=-1;
	}
	b[sy][sx]=0;
	int step=0;
	while (step<r*c){
		if(b[gy][gx]!=-1)break;
		for (int i=0;i<r*c;i++){
			if(b[i/c][i%c]==step){
				if(i/c!=0){
					if(b[i/c-1][i%c]==-1)b[i/c-1][i%c]=step+1;
				}
				if(i/c!=r-1){
					if(b[i/c+1][i%c]==-1)b[i/c+1][i%c]=step+1;
				}
				if(i%c!=0){
					if(b[i/c][i%c-1]==-1)b[i/c][i%c-1]=step+1;
				}
				if(i%c!=c-1){
					if(b[i/c][i%c+1]==-1)b[i/c][i%c+1]=step+1;
				}
			}
		}
	step++;
	}
	printf("%d\n",b[gy][gx]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d %d",&r,&c,&sy,&sx,&gy,&gx);
  ^
./Main.c:8:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   if(i%c==0)scanf("%*c%c",&a[i/c][i%c]);
             ^
./Main.c:9:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   else scanf("%c",&a[i/c][i%c]);
        ^