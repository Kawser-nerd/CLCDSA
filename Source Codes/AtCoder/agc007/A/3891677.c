#include<stdio.h>
#include<string.h>
int main() {
	long long int h,w,result=0;
	char str[500][500];
	scanf("%lld%lld", &h,&w);
	
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf(" %c", &str[i][j]);
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (str[i][j] == '#') {

				result++;

			}
		}
	}
	if(result==h+w-1){ printf("Possible"); }else{ printf("Impossible"); }
	
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &h,&w);
  ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %c", &str[i][j]);
    ^