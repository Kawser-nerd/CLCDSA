#include <stdio.h>

#define NMAX 1000

struct node{
	int size;
	int tots;
	int next;
} g[NMAX];

int main(void)
{
	int i, j, l, t, r, k, n;
	int start, riding, gi;
	int money, cur, bigmoney;
	
	scanf("%d", &t);
	for (j = 1; j <= t; j++){
		scanf("%d %d %d", &r, &k, &n);
		start = riding = 0;
		for (i = 0; i < n; i++){
			scanf("%d", &gi);
			g[i].size = gi;
			g[i].tots = gi;
			g[i].next = -1;
			riding += gi;
			while (riding > k){
				riding -= g[start].size;
				g[start].next = i;
				start++;
			}
			for (l = start; l < i; l++)
				g[l].tots += gi;
		}
		if (start == 0)
			g[0].next = 0;
		else{
			for (i = 0; start < n; i++){
				gi = g[i].size;
				riding += gi;
				while (riding > k && start < n){
					riding -= g[start].size;
					g[start].next = i;
					start++;
				}
				for (l = start; l < n; l++)
					g[l].tots += gi;
			}
		}
		
		bigmoney = money = cur = 0;
		for (i = 0; i < r; i++){
			money += g[cur].tots;
			if (money >= 1000000000){
				money -= 1000000000;
				bigmoney++;
			}
			cur = g[cur].next;
		}
		if (bigmoney > 0){
			printf("Case #%d: %d", j, bigmoney);
			for (i = 100000000; i > 0 && money / i == 0; i /= 10)
				putchar('0');
			if (money > 0)
				printf("%d", money);
			putchar('\n');
		}
		else
			printf("Case #%d: %d\n", j, money);
	}

	return 0;
}

