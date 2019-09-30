#include <stdio.h>

void solve(void)
{
	int n;
	int x0, y0, t0;
	int x1, y1, t1;
	int i;
	char ngTxt[] = "No", okTxt[] = "Yes", *pTxt = okTxt;
	
	x1 = y1 = t1 = 0;
	
	scanf("%d", &n);
	for(i=0;i<n;++i){
		int d;
		x0 = x1;
		y0 = y1;
		t0 = t1;
		
		scanf("%d %d %d", &t1, &x1, &y1);
		d = (x1>x0 ? x1-x0 : x0-x1) + (y1>y0 ? y1-y0 : y0-y1);
		if( d > t1 - t0 ){
			pTxt = ngTxt;
			break;
		}
		if( (t1-t0-d)%2 == 1 ){
			pTxt = ngTxt;
			break;
		}
	}
	printf("%s\n", pTxt);
}
int main(int argc, char **argv)
{
	solve();
	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &t1, &x1, &y1);
   ^