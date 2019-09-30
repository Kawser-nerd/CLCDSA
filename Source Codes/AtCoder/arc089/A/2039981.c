#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, i, t[100001]={0}, x[100001]={0}, y[100001]={0}, dt, dx, dy, f=0;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d %d %d", &t[i], &x[i], &y[i]);
	}
	
	for(i = 1; i <= n; i++){
	    dt = abs(t[i] - t[i-1]);
	    dx = abs(x[i] - x[i-1]);
	    dy = abs(y[i] - y[i-1]);
	    if((dt < (dx + dy)) || ((dt - (dx + dy))%2 != 0)){
	        f = 1;
	    }
	}
	printf("%s\n", f?"No":"Yes");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &t[i], &x[i], &y[i]);
   ^