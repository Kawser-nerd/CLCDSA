#include <stdio.h>

int N;
char cars[15][150];
int used[15];
char *order[15];
int count;

int valid()
{
	int i,j;
	char c,prv=0;
	char seen[30]={0};
	for (i=0;i<N;i++) {
		j=0;
		while (1) {
			c=order[i][j];
			if (!c)
				break;
			j++;
			if (prv != c) {
				if (seen[c-'a'])
					return 0;
				seen[c-'a']=1;
				prv = c;
			}
		}
	}
	return 1;
}

void go(int x)
{
	int i;
	if (!x) {
		if (valid()) {
			//for (i=0;i<N;i++)
			//	printf("%s ",order[i]);
			//puts("");
			count++;
		}
		return;
	}

	for (i=0;i<N;i++) {
		if (used[i])
			continue;
		used[i]=1;
		order[N-x]=cars[i];
		go(x-1);
		used[i]=0;
	}
}

int solve_one()
{
	int i;
	scanf("%d",&N);
	for (i=0;i<N;i++)
		scanf("%s",cars[i]);
	count = 0;
	go(N);
	return count;
}

int main()
{
	int i,T;
	scanf("%d",&T);
	for (i=0;i<T;i++) {
		fprintf(stderr, "%d\n",i);
		printf("Case #%d: %d\n",i+1,solve_one());
	}
}
