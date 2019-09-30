#include <stdio.h>

int main(){
	int N, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, i;
	double MT, mT;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%lf%lf", &MT, &mT);
		if(35 <= MT){
			a++;
		}
		if(30 <= MT && MT < 35){
			b++;
		}
		if(25 <= MT && MT < 30){
			c++;
		}
		if(25 <= mT){
			d++;
		}
		if(mT < 0 && 0 <= MT){
			e++;
		}
		if(MT < 0){
			f++;
		}
	}
	printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf", &MT, &mT);
   ^