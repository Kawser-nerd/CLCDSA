#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int carta[7][7];

int maybe[20];


int main (void)
{
	int t;
	int first, second;
	int value;
	int s = 0;
	FILE *fout = fopen("magic.out", "w");
	
	int i, j, k;
	
	scanf("%d", &t);
	
	for (i = 0; i < t; i++) {
		
		value = 0;
		
		memset(maybe, 0, sizeof(int) * 20);
		memset(carta, 0, sizeof(int) * 7 * 7);
		
		first = 0;
		second = 0;
		value = 0;
		s = 0;
		j= 0;
		k = 0;
		
		scanf("%d", &first);
printf("f=%d\n", first);
		
		for (j = 0; j < 4; j++) {
			
			for (k = 0; k < 4; k++) {
				
				scanf("%d", &carta[j][k]);
				
				if (j == first - 1) {
					maybe[carta[j][k]] = 1;
printf("may(1) - %d\n", carta[j][k]);
				}
			}
		}
		
		scanf("%d", &second);
printf("s=%d\n", second);
		
		s = 0;
		
		
		for (j = 0; j < 4; j++) {
			
			for (k = 0; k < 4; k++) {
				
				scanf("%d", &carta[j][k]);
				
				if (j == second - 1) {
					
printf("v %d s %d\t%d\n", value, s, maybe[carta[j][k]]);

					if (value && maybe[carta[j][k]]) {
						if (!s)
							fprintf(fout, "Case #%d: Bad magician!\n", i + 1);
						s = 1;
					}else if (maybe[carta[j][k]])
						value = carta[j][k];
				}
			}
			
		}
			
			if (!s && value) {
				fprintf(fout, "Case #%d: %d\n", i + 1, value);
			}
			
			if (!s && !value) {
				fprintf(fout, "Case #%d: Volunteer cheated!\n", i + 1);
			}
		
	}
	
	return 0;
	
}