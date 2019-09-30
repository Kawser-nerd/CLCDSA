#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int equacao(double c, double f, double x, double z) {
	if (c < ((f *x) / (z + f)))
		return 1;
	return 0;
}

int main (void)
{
	int t;
	double c, f, x;
	
	double atual;
	
	double time;
	
	int i;
	
	FILE *fout = fopen("cookie.out", "w");
	
	scanf("%d", &t);
	
	for (i = 0; i < t; i++) {
		
		atual = 2.0;
		
		time = 0.0;
		
		scanf("%lf %lf %lf", &c, &f, &x);
		
		while (1) {
			
			if (equacao(c, f, x, atual)) {
				
				time += c / atual;
				atual += f;
// printf("i %d\t%lf\n", i, time);
			} else {
				
				time += x / atual;
				
				fprintf(fout, "Case #%d: %0.7lf\n", i + 1, time);
				break;
			}
			
		}
		
	}
	
	return 0;
	
}