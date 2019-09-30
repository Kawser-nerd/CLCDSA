#include <stdio.h>

#define ZERO 0
int main(){
	int slime_count;

	scanf("%d",&slime_count);

	int a[slime_count];                      /*???????????*/
	int i = ZERO,    j     = ZERO;           /*??????*/
	int consecutive_count  = 1;              /*?????????????????*/
	int color_change_count = 0;              /*????????????*/

	/*??????????????*/
	for(i = 0; i < slime_count ; i++){
		scanf("%d", &a[i]);
	}

	for(j = 0; j < slime_count ; j++){
		if(j == slime_count - 1)break;
		if(a[j] == a[j+1]){
			consecutive_count++;
			continue;
		}

		color_change_count += consecutive_count/2;
		consecutive_count = 1;
	}
	color_change_count += consecutive_count/2;

	printf("%d",color_change_count);

} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&slime_count);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^