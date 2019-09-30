#include<stdio.h>
#include<math.h>

int main()
{
	int i, j=0, n, keta, h, temp;
	scanf("%d", &n);
	temp = n;
	if(n == 1) printf("Not Prime\n");
	else if(n > 1){	
		for(i = 0; i < 10; ++i){
			if(n / pow(10,i) >= 1){
				++j;
			}else if(n / pow(10,i) < 1){
				keta = j;
				break;
			}
		}
		int a[keta], ketawa=0;	
		for(i = keta-1; i >= 0; --i){
			a[i] = n / pow(10, i);
			n -= a[i] * pow(10, i);
			ketawa += a[i];
		}
		n = temp;
		
		if(a[0] != 5 && a[0]%2 != 0 && ketawa%3 != 0){
			h = 1;
		}else{
			for(i=2; i<n; ++i){
				if(n%i == 0){
					h = 0;
					break;
				}else{
					h = 1;
				}
			}
		}
		switch(h){
		case 0:
			printf("Not Prime\n");
			break;
		case 1:
			printf("Prime\n");
			break;
		}
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^