#include <stdio.h>

int main(int argc, char** argv)
{
	int n;
	short a[100000+2]={0};
	int total = 0;
	int i;
	
	scanf("%d", &n);
	for(i=0;i<n;++i){
		scanf("%hd", a+(i+1));
		total += (a[i]>a[i+1]?a[i]-a[i+1]:a[i+1]-a[i]);
	}
	total += (a[n]>a[n+1]?a[n]-a[n+1]:a[n+1]-a[n]);
	for(i=0;i<n;++i){
		int x, y, z;
		x=(a[i+0]>a[i+1]?a[i+0]-a[i+1]:a[i+1]-a[i+0]);
		y=(a[i+1]>a[i+2]?a[i+1]-a[i+2]:a[i+2]-a[i+1]);
		z=(a[i+0]>a[i+2]?a[i+0]-a[i+2]:a[i+2]-a[i+0]);
		printf("%d\n", total - x - y + z);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd", a+(i+1));
   ^