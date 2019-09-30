#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	int t, l, c;
	char bolo[27][27], car;
	scanf("%d", &t);
	
	for(int i = 0; i< t; i++){
		scanf("%d %d", &l, &c);
		for(int j = 0; j<l; j++)	
			scanf("%s", bolo[j]);
		
		for(int j = 0; j < l; j++){
			car = '?';
			for(int k = 0; k < c; k++){
				if(bolo[j][k] != '?'){
					car = bolo[j][k]; 
				}
				else{
					bolo[j][k] = car;
				}
			
			}
		}
		for(int j = l-1; j >= 0; j--){
			car = '?';
			for(int k = c-1; k >= 0; k--){
				if(bolo[j][k] != '?'){
					car = bolo[j][k]; 
				}
				else{
					bolo[j][k] = car;
				}
			
			}
		}	
		for(int j = 0; j < c; j++){
			car = '?';
			for(int k = 0; k < l; k++){
				if(bolo[k][j] != '?'){
					car = bolo[k][j]; 
				}
				else{
					bolo[k][j] = car;
				}
			
			}
		}
		
		for(int j = c-1; j >= 0; j--){
			car = '?';
			for(int k = l-1; k >= 0; k--){
				if(bolo[k][j] != '?'){
					car = bolo[k][j]; 
				}
				else{
					bolo[k][j] = car;
				}
			
			}
		}
		printf("Case #%d:\n", i+1);
		for(int j = 0; j<l; j++)	
			printf("%s\n", bolo[j]);
	}
	
	
	return 0;
}
/*
3
3 3
G??
?C?
??J
3 4
CODE
????
?JAM
2 2
CA
KE

* 
*/
