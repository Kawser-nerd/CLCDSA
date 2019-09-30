#include <stdio.h>

int cards[10000];

int main()
{

	int ppp,qq;
	int K, i, n, a;
	int pointer, count;

	scanf("%d", &ppp);
	for (qq=0; qq<ppp; qq++){
	
	scanf("%d", &K);

	pointer = 0;
	count = 0;
	for (i=0; i<10000; i++) cards[i] = 0;

	for (i=1; i<=K; i++){
		while (count != i){
			pointer = pointer + 1;
			if (pointer > K) pointer = 1;
			while (cards[pointer] != 0){
				pointer = pointer + 1;
				if (pointer > K) pointer = 1;

			}
			count = count + 1;
		}
		if (count == i){

			cards[pointer] = i;
			count = 0;
		}
	}
	
	printf("Case #%d: ",qq+1);
	scanf("%d", &n);
	for (i=0; i<n-1; i++){
		scanf("%d", &a);
		printf("%d ", cards[a]);
	}
	scanf("%d", &a);
	printf("%d\n", cards[a]);





	}	

	return 0;
}
