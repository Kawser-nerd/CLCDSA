#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int t, i, n, R, o, Y, g, B, v, j, imp;
	char str[1002];
	
	scanf("%d", &t);

	for (i = 0; i < t; i++){
		imp = 0; 
		scanf("%d%d%d%d%d%d%d", &n, &R, &o, &Y, &g, &B, &v);

		if (R > n/2 || Y > n/2 || B > n/2 )
			printf("Case #%d: IMPOSSIBLE\n", i+1);
		else{
			if (R >= Y && R >= B){
				for (j = 0; j < n; j+=2){
					if (R > 0){
						str[j] = 'R';
						R--;
					}
					else if (Y > 0){
						str[j] = 'Y';
						Y--;
					}
					else if (B > 0){
						str[j] = 'B';
						B--; 
					}
				}
				for (j = 1; j < n; j+=2){
					if (R > 0){
						str[j] = 'R';
						R--;
					}
					else if (Y > 0){
						str[j] = 'Y';
						Y--;
					}
					else if (B > 0){
						str[j] = 'B';
						B--; 
					}
				}
				str[n] = '\0';
				printf("Case #%d: %s\n", i+1, str);
			} else if (Y >= R && Y >= B){
				for (j = 0; j < n; j+=2){
					if (Y > 0){
						str[j] = 'Y';
						Y--;
					}
					else if (R > 0){
						str[j] = 'R';
						R--;
					}
					else if (B > 0){
						str[j] = 'B';
						B--; 
					}
				}
				for (j = 1; j < n; j+=2){
					if (Y > 0){
						str[j] = 'Y';
						Y--;
					}
					else if (R > 0){
						str[j] = 'R';
						R--;
					}
					else if (B > 0){
						str[j] = 'B';
						B--; 
					}
				}
				str[n] = '\0';
				printf("Case #%d: %s\n", i+1, str);
			} else if (B >= R && B >= Y){
				for (j = 0; j < n; j+=2){
					if (B > 0){
						str[j] = 'B';
						B--;
					}
					else if (R > 0){
						str[j] = 'R';
						R--;
					}
					else if (Y > 0){
						str[j] = 'Y';
						Y--; 
					}
				}
				for (j = 1; j < n; j+=2){
					if (B > 0){
						str[j] = 'B';
						B--;
					}
					else if (R > 0){
						str[j] = 'R';
						R--;
					}
					else if (Y > 0){
						str[j] = 'Y';
						Y--; 
					}
				}
				str[n] = '\0';
				printf("Case #%d: %s\n", i+1, str);
			}
		}
		
	}

	
	return 0;
}
