#include <stdio.h>
#define MAXS 100
#define MAXLEN 100
#define INF 1000000000

//#define DEBUG

int table[2][MAXS];
char name[MAXS][MAXLEN+1];
int main()
{
	int i, j, k, n, q, min;
	int ncase, icase;
	char query[MAXLEN+1];
	int *last, *now, *ptmp;

	scanf("%d", &ncase);
	for(icase = 0; icase < ncase; ++icase){
		scanf("%d ", &n);
		for(i=0; i<n; ++i){
			fgets(name[i], MAXLEN+1, stdin);
			table[0][i] = 0;
		}
		last = table[0];
		now = table[1];

		scanf("%d ", &q);
		for(i=0; i<q; ++i){
			fgets(query, MAXLEN+1, stdin);
			for(j=0; j<n; ++j){
				if(!strcmp(query, name[j])){
					now[j] = INF;
					continue;
				}
				now[j] = last[j];
				for(k=0; k<n; ++k){
					if(k == j)
						continue;
					if(last[k] + 1 < now[j])
						now[j] = last[k] + 1;
				}
			}
#ifdef DEBUG
			for(j=0; j<n; ++j)
				printf("%d ", now[j]);
			printf("\n");
#endif
			ptmp = now;
			now = last;
			last = ptmp;
		}
		min = INF;
		for(i=0; i<n; ++i){
			if(last[i] < min)
				min = last[i];
		}
		printf("Case #%d: %d\n", icase+1, min);
	}
	return 0;
}
