#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int t, i, d, j, n, km, sp;
	long double time, taux;
	
	
	scanf("%d", &t);

	for (i = 0; i < t; i++){
		scanf("%d%d", &d, &n);
		
		
		time = 0; 
		for (j = 0; j < n; j++){
			scanf("%d%d", &km, &sp);
			taux = (long double)(d-km)/sp;
			if (taux > time)
				time = taux;
		}
		 
		printf("Case #%d: %.6Lf\n", i+1, (long double)d/time );
		
		
	}

	
	return 0;
}