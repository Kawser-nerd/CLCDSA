#include <stdio.h>

#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define en(a,b) ((a)*(a)+(b)*(b))

int x,y,r;
int x2,y2,x3,y3;


int red(){
	if(max(x2,x3)>=(r+x)&&max(y2,y3)>=(r+y)&&min(y2,y3)<=(y-r)&&min(x2,x3)<=(x-r)) return 0;
	else return 1;
}

int blue(){
	int rr = r*r;
	if(en(x2-x,y2-y)<=rr&&en(x3-x,y2-y)<=rr&&en(x2-x,y3-y)<=rr&&en(x3-x,y3-y)<=rr) return 0;
	else return 1;
}

int main(){
	scanf("%d %d %d",&x,&y,&r);
	scanf("%d %d %d %d",&x2,&y2,&x3,&y3);
	if(red()) printf("YES\n");
	else printf("NO\n");
	if(blue()) printf("YES\n");
	else printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&x,&y,&r);
  ^
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&x2,&y2,&x3,&y3);
  ^