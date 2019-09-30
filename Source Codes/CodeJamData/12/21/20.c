#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int list[1024] = {0};

int check(int sum, double score, int N, int id){
	double need = score;
	double gate = list[id] + score;
	for (int i = 0; i<N; i++){
		if (id == i)
			continue;
		if (list[i] < gate){
			need += (gate - list[i]);
		}
	}
	if (need > sum)
		return 1;
	else
		return 0;
}

int main(){
	int T = 0, N = 0;

	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		scanf("%d", &N);
		int sum = 0;
		for (int i = 0; i<N; i++){
			scanf("%d", &list[i]);
			sum += list[i];
		}

		printf("Case #%d:", cas);
		for (int i = 0; i<N; i++){
			double high = 100, low = 0.0, mid = 0.0;
			int x = 512;
			while (x--){
				mid = (high + low) / 2;
				double score = (mid * sum / 100.0);
				if (check(sum, score, N, i)){
					high = mid;
				}else{
					low = mid;
				}
			}
			printf(" %.9lf", mid);
		}
		printf("\n");
	}
	return 0;
}
