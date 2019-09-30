#include<stdio.h>
#include<math.h>
#include<string.h>
int main() {
	int sum=0;
	int n,x=0,y;
	char a[101];
	scanf("%d",&n);
	getchar();
	scanf("%s",a);
	for(int i=0;i<n;i++){
		if(a[i]=='I'){
			x++;
		}
		if(a[i]=='D'){
			x--;
		}
		if(sum<x){
			sum=x;
		}
	}
	printf("%d",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",a);
  ^