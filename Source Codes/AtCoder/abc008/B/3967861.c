#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
	char **name;
	int n;
	int count, max, maxi;
	scanf("%d", &n);
	name = malloc(sizeof(char *) * n);
	for(int i = 0; i < n; i++){
		name[i] = malloc(55);
		scanf("%s", name[i]);
	}
	maxi = max = 0;
	for(int i = 0; i < n; i++){
		count = 0;
		for(int j = 0; j < n; j++){
			if(!strcmp(name[i], name[j])){
				count++;
			}
		}
		if(max < count){
			max = count;
			maxi = i;
		}
	}
	printf("%s\n", name[maxi]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", name[i]);
   ^