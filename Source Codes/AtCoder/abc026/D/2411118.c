#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979

int A,B,C;
double a,b,c;
long double ans;

void kansuu(long double p, long double s){
	if(fabs(s) < 0.000000000001l){
		ans = p;
	}else{
		for(long double i=p;;i+=s){
		
			if(a*i + b*sin(c*i*PI) == 100.0){
				ans = i;
				break;
			}else if( ( a*i + b*sinl(c*i*PI) > 100.0 && a*(i+s) + b*sinl(c*(i+s)*PI) < 100.0 ) || ( a*i + b*sinl(c*i*PI) < 100.0 && a*(i+s) + b*sinl(c*(i+s)*PI) > 100.0 ) ){
				kansuu(i, s*0.1);
				break;
			}
		}
	}
}

void change(int *x, int *y){
	int z;
	z = *x;
	*x = *y;
	*y = z;
}
/*int compare_int(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
*/
int main(void){
	scanf("%d %d %d", &A, &B, &C );
	
	a = (long double)A;
	b = (long double)B;
	c = (long double)C;
	kansuu(0.0, 1.0);

	printf("%.13llf", ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:9: warning: use of ‘ll’ length modifier with ‘f’ type character [-Wformat=]
  printf("%.13llf", ans);
         ^
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &A, &B, &C );
  ^