#include <stdio.h>

int main (void){

	int H, W;
	scanf("%d", &H);
	scanf("%d", &W);

	int i, j;
	char a[1000][1000];

 	for(i = 0; i < H; i++){
   		scanf("%s", a[i]);  
 	}
	
	char b[1000][1000];

	for(i = 0; i < H + 2; i++){
                for(j = 0; j < W + 2; j++){
                        b[i][j] = '#';
                }
        }

	for(i = 1; i < H + 1; i++){
                for(j = 1; j < W + 1; j++){
                        
			b[i][j] = a[i - 1][j - 1];
                }
        }	

	for(i = 0; i < H + 2; i++){
  		 printf("%s\n", b[i]);  
 	}	

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &H);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &W);
  ^
./Main.c:13:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%s", a[i]);  
      ^