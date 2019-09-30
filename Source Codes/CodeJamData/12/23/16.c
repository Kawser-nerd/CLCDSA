#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int list[640]= {0};
int all_sum[1<<21] = {0};
int comp(const void* a, const void* b){
	return *(int*)a-*(int*)b;
}

int print(int mask){
	int id = 0;
	int first = 1;
	while (mask){
		if (mask & 1){
			if (first){
				printf("%d", list[id]);
				first = 0;
			}else{
				printf(" %d", list[id]);
			}
		}
		mask /= 2;
		id++;
	}
	printf("\n");
	return 0;
}

int check(int cas, int num, int msk, int N){
	for (int i = 1; i<(1<<N); i++){
		int mask = i;
		int x = 0, id = 0;
		int kkk = msk;
		while (mask){
			if ((mask & 1) != 0 && (kkk & 1) == 0){
				x += list[id];
			}
			mask /= 2;
			kkk/=2;
			id++;
		}

		if (x == num){
			printf("Case #%d:\n", cas);
			print(i);
			print(msk);
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
    int T = 0, N = 0;

	scanf("%d", &T);
    for (int cas = 1; cas<=T; cas++){
		int sum = 0;
		scanf("%d", &N);
        for (int i = 0; i<N; i++){
            scanf("%d", &list[i]);
			sum += list[i];
        }

		for (int x = 1; x < (1<<N); x++){
			int mask = x, id = 0;
			int num = 0;
			while (mask){
				if (mask & 1){
					num += list[id];
				}
				id++;
				mask /= 2;
			}
			all_sum[x] = num;
		}
		qsort(all_sum, (1<<N), sizeof(int), comp);
		
		int cont = 1;
		for (int x = 1; x < (1<<N) && cont == 1; x++){
			int mask = x, id = 0;
			int num = 0;
			while (mask){
				if (mask & 1){
					num += list[id];
				}
				id++;
				mask /= 2;
			}

			if (bsearch(&num, all_sum, (1<<N), sizeof(int), comp) != NULL){
				int ret = check(cas, num, x, N);
				if (ret == 1)
					cont = 0;
			}
		}

		if (cont == 1){
			printf("Case #%d:\n", cas);
			printf("Impossible\n");
		}
			
    }
    return 0;
}
