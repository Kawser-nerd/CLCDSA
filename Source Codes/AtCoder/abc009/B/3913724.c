#include <stdio.h>

int main(){
	int n, in, m1, m2;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &in);
		if(in > m1){
			m2 = m1;
			m1 = in;
		}
		if(m1 > in && in > m2){
			m2 = in;
		}
	}
	printf("%d\n", m2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &in);
   ^