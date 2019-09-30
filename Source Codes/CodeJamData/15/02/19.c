#include <stdio.h>
#include <string.h>
#include <conio.h>
void main(){
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("output4.out", "w", stdout);
	int cases;
	int i = 0;
	int j = 0;
	int diners;
	int sum1 = 0;
	int sum2 = 0;
	int pancakes[1000];
	int minutes[1000];
	int casecount;
	scanf("%d", &cases);
	for (casecount = 1; casecount <= cases; casecount++){
		scanf("%d", &diners);
		for (i = 0; i<diners; i++){
			scanf("%d", &pancakes[i]);
		}
		for (i = 0; i<diners; i++){
			for (j = i; j<diners; j++){
				if (pancakes[j]<pancakes[i]){
					int temp = pancakes[i];
					pancakes[i] = pancakes[j];
					pancakes[j] = temp;
				}
			}
		}
		for (i = 1; i <= pancakes[diners - 1]; i++){
			sum1 = 0;
			sum2 = 0;
			for (j = diners - 1; j >= 0; j--){
				if (pancakes[j]>i){
					int times1 = pancakes[j] / i;
					int times2 = pancakes[j] / (i + 1);
					if (pancakes[j] % i == 0)
						times1--;
					if (pancakes[j] % (i + 1) == 0)
						times2--;
					sum1 = sum1 + times1;
					sum2 = sum2 + times2;
				}

			}
			if ((sum1<pancakes[diners - 1] - i) && sum1 + i<sum2 + i + 1)
				break;
			if (i == pancakes[diners - 1])
				break;
		}
		minutes[casecount] = sum1 + i;
	}
	for (casecount = 1; casecount <= cases; casecount++)
	{
		printf("Case #%d: %d \n", casecount, minutes[casecount]);
	}
}
