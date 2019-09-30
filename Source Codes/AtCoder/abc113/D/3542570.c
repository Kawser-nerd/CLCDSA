#include<stdio.h>
int main() {
	long long int h,w,k,memo,result;
	long long int two[10] = { 1,2,3,5,8,13,21,34,55,256,512 };
	scanf("%lld%lld%lld", &h, &w, &k);
	long long int s[105][10] = {};
	s[h + 1][k] = 1;
	for (int i = h; i >= 1; i--) {
		for (int j = 1; j <= w; j++) {
			memo = 0;
			if (j == 1 || j == w) {
				memo += two[w - 2] * s[i + 1][j];
			}
			else {
				memo += (two[j-2]*two[w-j-1]) * s[i + 1][j];
			}

			if (j == 1||j==w-1) {
				memo += two[w - 3] * s[i + 1][j+1];
			}
			else if (j == w) {

			}
			else
			{
				memo += (two[j-2]*two[w - j-2]) * s[i + 1][j+1];
			}

			if (j == 1) {
				
			}
			else if (j == w||j==2) {
				memo += two[w - 3] * s[i + 1][j - 1];
			}
			else
			{
				memo += (two[j - 3] * two[w - j - 1]) * s[i + 1][j-1];
			}
			memo %= 1000000007;
			s[i][j] = memo;
		}
	}
	printf("%lld", s[1][1]);

} ./Main.c: In function ‘main’:
./Main.c:4:54: warning: excess elements in array initializer
  long long int two[10] = { 1,2,3,5,8,13,21,34,55,256,512 };
                                                      ^
./Main.c:4:54: note: (near initialization for ‘two’)
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &h, &w, &k);
  ^