#include<stdio.h>
#include<string.h>

int main()
{
	int n, i, j, ans = 1;
	
	scanf("%d", &n);
	
	char w[n][101], end;
	
	for(i = 0; i < n; i++){
		scanf("%s", w[i]);
	}
	
	end = w[0][strlen(w[0]) - 1];
	
	for(i = 0; i < n; i++){
		for(j = 0; j < i; j++){
			if(strcmp(w[i],w[j]) == 0){
				ans = 0;
				break;
			}
		}

		if(ans == 0){
			break;
		}
		
		if(i >= 1){
			if(w[i][0] != end){
				ans = 0;
				break;
			}else{
				end = w[i][strlen(w[i]) - 1];
			}
		}
	}
	
	if(ans == 1){
		printf("Yes");
	}else{
		printf("No");
	}
	

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", w[i]);
   ^