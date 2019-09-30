#include <stdio.h>

#define MAXN 2100

char s[1024];

int from[MAXN], to[MAXN];

int n;
int roomn;
int rooms[MAXN];
int room[MAXN][MAXN]; //room[i][j] = 1 if vertex j is in ith room

int checkc(int c)
{
	int i, j, k, ret;
	FILE *f;
	f = fopen("sat", "wt");
	fprintf(f, "c c=%d\n", c);
	fprintf(f, "p cnf %d %d\n", c*n, roomn*c+c*(c-1)/2*n+n);
	for (i = 0; i < roomn; i++) {
		for (j = 0; j < c; j++) {
			for (k = 0; k < n; k++) {
				if (room[i][k]) fprintf(f, "%d ", k*c+j+1);
			}
			fprintf(f, "0\n");
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < c; j++) {
			for (k = j+1; k < c; k++) {
				fprintf(f, "-%d -%d 0\n", i*c+j+1, i*c+k+1);
			}
		}
		for (j = 0; j < c; j++) {
			fprintf(f, "%d ", i*c+j+1);
		}
		fprintf(f, "0\n");
	}
	fclose(f);
	system("picosat < sat > sol");
	f = fopen("sol", "rt");
	fgets(s, 1020, f);
	fclose(f);
	ret = strncmp(s, "s SATISFIABLE", 13) == 0;
//	fprintf(stderr, "c=%d ret=%d\n", c, ret);
	return ret;
}

int main(void)
{
	int ti, tn;
	FILE *f;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ti++) {
		int m, i, j, k, l, r, minsize;
		scanf("%d %d", &n, &m);
		for (i = 0; i < m; i++) {
			scanf("%d", from+i);
			from[i]--;
		}
		for (i = 0; i < m; i++) {
			scanf("%d", to+i);
			to[i]--;
		}
		roomn = 1;
		rooms[0] = n;
		for (i = 0; i < n; i++) {
			room[0][i] = 1;
		}
		for (i = 0; i < m; i++) {
			int size = 0;
			for (j = 0; j < roomn; j++) {
				if (room[j][from[i]] && room[j][to[i]]) break;
			}
			// split jth room
			for (k = 0; k < n; k++) {
				room[roomn][k] = 0;
			}
			rooms[roomn] = 2;
			room[roomn][from[i]] = 1;
			room[roomn][to[i]] = 1;
			for (k = from[i]+1; k < to[i]; k++) {
				if (room[j][k]) {
					room[j][k] = 0;
					room[roomn][k] = 1;
					rooms[roomn]++;
					rooms[j]--;
				}
			}
			roomn++;
		}
		minsize = n;
		for (i = 0; i < roomn; i++) {
			if (rooms[i] < minsize) minsize = rooms[i];
		}
		l = 1;
		r = minsize;
		while (l < r) {
			int m = l+(r-l+1)/2;
			if (checkc(m)) l = m;
			else r = m-1;
		}
		printf("Case #%d: %d\n", ti, l);
		f = fopen("sol", "rt");
		fgets(s, 1020, f);
		k = 0;
		while (k < n) {
			char *p;
			fgets(s, 1020, f);
			p = s+2;
			while ((i = strtol(p, &p, 10)) != 0) {
				if (i > 0) {
					printf("%d ", ((i-1)%l)+1);
					fflush(stdout);
					k++;
				}
			}
		}
		printf("\n");
		fclose(f);
	}
	return 0;
}
