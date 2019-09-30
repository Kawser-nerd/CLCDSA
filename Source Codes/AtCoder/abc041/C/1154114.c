#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	int height;
}student;

student *sort(student *procession, int N){
	student *ans = (student *)malloc(sizeof(student) * N);
	if(N == 1){
		ans[0].num = procession[0].num;
		ans[0].height = procession[0].height;
	}
	else{
		int N1 = N / 2;
		int N2 = (N + 1) / 2;
		student *sub1 = sort(&procession[0] , N1);
		student *sub2 = sort(&procession[N1], N2);
		int i, j, k;
		for(i = 0, j = 0, k = 0; i < N; i++){
			if((sub1[j].height < sub2[k].height && j != N1) || (k == N2)){
				ans[i].num = sub1[j].num;
				ans[i].height = sub1[j].height;
				j++;
			}
			else{
				ans[i].num = sub2[k].num;
				ans[i].height = sub2[k].height;
				k++;
			}
		}
		free(sub1);
		free(sub2);
	}
	//free(procession);
	return ans;
}

int main(){
	int N, i;
	scanf("%d", &N);
	student *procession = (student *)malloc(sizeof(student) * N);
	for(i = 0; i < N; i++){
		procession[i].num = i;
		scanf("%d", &(procession[i].height));
	}
	student *ans = sort(procession, N);
	for(i = N - 1; i >= 0; i--){
		printf("%d\n", ans[i].num + 1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &(procession[i].height));
   ^