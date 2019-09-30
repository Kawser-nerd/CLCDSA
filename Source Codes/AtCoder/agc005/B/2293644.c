#include <stdio.h>
#include <stdlib.h>
#define int long long

typedef struct {
	int *array;
	int N;
}stack;

stack *make_stack(int maxN){
	stack *s = (stack *)malloc(sizeof(stack));
	s->array = (int *)malloc(sizeof(int) * maxN);
	s->N = 0;
	return s;
}

int element_num_stack(stack *s){
	return s->N;
}

void add_data_stack(int val, stack *s){
	s->array[s->N] = val;
	s->N++;
}

int take_data_stack(stack *s){
	if(s->N == 0){
		printf("no data in the stack\n");
	}
	s->N--;
	return s->array[s->N];
}

int look_data_stack(stack *s){
	if(s->N == 0){
		printf("no data in the stack\n");
	}
	else{
		return s->array[s->N - 1];
	}
}

void flush_stack(stack *s){
	s->N = 0;
}

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, i, j, ans = 0, garbage;
	scanf("%lld", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
	}
	int *L = (int *)malloc(sizeof(int) * N);
	int *R = (int *)malloc(sizeof(int) * N);
	stack *sL = make_stack(N);
	stack *sR = make_stack(N);
	for(j = 0; j < N; j++){
		while(1){
			if(element_num_stack(sL) == 0){
				L[j] = 0;
				break;
			}
			else if(a[j] > a[look_data_stack(sL)]){
				L[j] = look_data_stack(sL) + 1;
				break;
			}
			garbage = take_data_stack(sL);
		}
		add_data_stack(j, sL);
	}
	flush_stack(sL);
	for(j = N - 1; j >= 0; j--){
		while(1){
			if(element_num_stack(sR) == 0){
				R[j] = N - 1;
				break;
			}
			else if(a[j] > a[look_data_stack(sR)]){
				R[j] = look_data_stack(sR) - 1;
				break;
			}
			garbage = take_data_stack(sR);
		}
		add_data_stack(j, sR);
	}
	flush_stack(sR);
	for(j = 0; j < N; j++){
		ans += a[j] * (j - L[j] + 1) * (R[j] - j + 1);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:53:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^