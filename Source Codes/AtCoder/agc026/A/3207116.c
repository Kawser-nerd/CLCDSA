#include<stdio.h>

int main() {
	
	int n, a[106] = {},memo=100000,result=0,count=1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		
		if (memo == a[i]) {
			count++;
		}
		else {
			result = (count / 2)+result;
			count = 1;
			memo=a[i];
		}
	}
  result = (count / 2)+result;
	printf("%d", result);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^