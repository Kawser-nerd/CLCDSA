#include <stdio.h>
#include <stdlib.h>

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

long long max(long long a, long long b){
	return a >= b ? a : b;
}

//A?????0?1
//1???????????????????
int largest_rectangle(int H, int W, int **A){
	int i, j, garbage, ans = 0;
	int **T = (int **)malloc(sizeof(int *) * H);
	int *L = (int *)malloc(sizeof(int) * W);
	int *R = (int *)malloc(sizeof(int) * W);
	stack *sL = make_stack(W);
	stack *sR = make_stack(W);
	for(i = 0; i < H; i++){
		T[i] = (int *)malloc(sizeof(int) * W);
		for(j = 0; j < W; j++){
			if(i == 0){
				T[i][j] = A[i][j];
			}
			else{
				T[i][j] = (T[i - 1][j] + 1) * A[i][j];
			}
		}

		for(j = 0; j < W; j++){
			while(1){
				if(element_num_stack(sL) == 0){
					L[j] = 0;
					break;
				}
				else if(T[i][j] > T[i][look_data_stack(sL)]){
					L[j] = look_data_stack(sL) + 1;
					break;
				}
				garbage = take_data_stack(sL);
			}
			add_data_stack(j, sL);
		}
		flush_stack(sL);

		for(j = W - 1; j >= 0; j--){
			while(1){
				if(element_num_stack(sR) == 0){
					R[j] = W - 1;
					break;
				}
				else if(T[i][j] > T[i][look_data_stack(sR)]){
					R[j] = look_data_stack(sR) - 1;
					break;
				}
				garbage = take_data_stack(sR);
			}
			add_data_stack(j, sR);
		}
		flush_stack(sR);

		for(j = 0; j < W; j++){
			ans = max(ans, ((T[i][j] + 1) / 2) * ((R[j] - L[j] + 2) / 2));
		}
	}
	return ans;
}

int main(){
	int H, W, i, j, count;
	scanf("%d%d", &H, &W);
	char **S = (char **)malloc(sizeof(char *) * H);
	for(i = 0; i < H; i++){
		S[i] = (char *)malloc(sizeof(char) * (W + 1));
		scanf("%s", S[i]);
	}
	int **A = (int **)malloc(sizeof(int *) * (2 * H - 1));
	for(i = 0; i < 2 * H - 1; i++){
		A[i] = (int *)malloc(sizeof(int) * (2 * W - 1));
		for(j = 0; j < 2 * W - 1; j++){
			A[i][j] = 1;
		}
	}
	for(i = 1; i < H; i++){
		for(j = 1; j < W; j++){
			count = 0;
			if(S[i][j] == '#'){
				count++;
			}
			if(S[i - 1][j] == '#'){
				count++;
			}
			if(S[i][j - 1] == '#'){
				count++;
			}
			if(S[i - 1][j - 1] == '#'){
				count++;
			}
			if(count == 1 || count == 3){
				A[2 * i - 1][2 * j - 1] = 0;
			}
		}
	}
	printf("%d\n", largest_rectangle(2 * H - 1, 2 * W - 1, A));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:111:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:115:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S[i]);
   ^