#include <stdio.h>

int main (void){

	int a[3];
	int i, j, temp = 0, count = 0;

	for(i = 0; i < 3; i++){
		scanf("%d", &a[i]);
	}

	for(i = 0; i < 2; i++){
		for(j = 1; j < 3; j++){
			
			if(a[i] < a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;	
			}
		}
	}

	count = a[0] - a[1];
	a[1] = a[0];
	a[2] = a[2] + count;

	while(a[2] < a[0]){
		a[2] = a[2] + 2;
		count++;
	}

	if(a[0] == a[2]){
		printf("%d\n", count);
		return 0;
	}else if(a[2] > a[0]){
		count = count + 1;
		printf("%d\n", count);
		return 0;
	}

} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^