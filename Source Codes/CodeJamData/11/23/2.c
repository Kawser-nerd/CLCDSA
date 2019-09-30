#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAXX 2100

int deg[MAXX];
int sousedi[MAXX][MAXX];


int intcomp(int *a, int *b)
{
	if (*a<*b) return -1;
	if (*a==*b) return 0;
	return 1;
}

int m,n;
int barev;
int color[MAXX];



int csearch(int *pole, int size, int x)
{
	void *bs = bsearch(&x, pole, size, intcomp);
	return (int *)bs - pole;
#if 0
	int i;
	for (i=0; i<size; i++) {
		if (pole[i]==x) {
			return i;
		}
	}
	assert(0);
#endif
}




// najdi dalsi vrchol po i,j, na stene po prave strane hrany i->j
int nextv(int i, int j)
{
	int a;
	a = csearch(&sousedi[j][0], deg[j], i);
	assert(sousedi[j][a] == i);
	return sousedi[j] [a>0? a-1 : deg[j]-1];
}

// zpracuj stenu po prave strane hrany i->j
void rekuCount(int i, int j)
{
//	printf("[%d %d:\n",i,j);
	int d = 1; // pocet vrcholu
	int v0 = i;
	int k;

	// je tam vubec stena?
	if (i==j+1 || (j==n && i==1)) {
//		printf(">");
		return;
	}

	// spocitej vrcholy
	while (1) {
		if (j==v0) {
			break;
		}
		k = nextv(i,j);
		d++;
		i = j;
		j = k;
		// rekurze
		rekuCount(j,i);
	}
	// min nez barev? -> slev
//	printf("{%d}", d);
	if (d < barev) {
		barev = d;
	}
//	printf("]");
}

void rekuCol(int i, int j)
{
	int v0 = i;

	int q1 = color[i], q2 = color[j], q3 = 0;
	int c = 1;
	int d = 2;
	int k;

	// je tam vubec stena?
	if (i==j+1 || (j==n && i==1)) {
		return;
	}

	// spocitej vrcholy
	while (1) {
		d++;
		k = nextv(i,j);
		if (k==v0) {
			break;
		}
		if (d<=barev) {
			while (c==q1 || c==q2) {
				c++;
			}
			if (q3==0) {
				q3 = c;
			}
		} else {
			c = (d-barev)&1 ? q2:q3;
		}
		color[k] = c;
		c++;

		i = j;
		j = k;
		// rekurze
		rekuCol(j,i);
	}
	// zbyva hrana j->k
	rekuCol(k,j);
}

void dump()
{
	int i;
	printf("%d\n", barev);
	printf("1 2");
	for (i=3; i<=n; i++) {
		assert (color[i]<=barev);
		printf(" %d",color[i]);
	}
	printf("\n");
}

void docase()
{
	int from[MAXX], to[MAXX];
	int i,j;

	barev = MAXX;
	//read data
	scanf(" %d %d", &n, &m);
	for (i=0; i<m; i++) {
		scanf(" %d", from+i);
	}
	for (i=0; i<m; i++) {
		scanf(" %d", to+i);
	}

	//neighbours lists
	bzero(deg, sizeof(int)*(n+5));
	for (i=0; i<m; i++) {
		sousedi[from[i]][deg[from[i]]] = to[i];
		deg[from[i]]++;
		sousedi[to[i]][deg[to[i]]] = from[i];
		deg[to[i]]++;
	}
	for (i=1; i<=n; i++) {
		sousedi[i][deg[i]] = (i>1)? i-1 : n;
		sousedi[i][deg[i]+1] = (i<n)? i+1 : 1;
		deg[i] += 2;
		qsort(&(sousedi[i][0]), deg[i], sizeof(int), intcomp);

//		printf("%d:",i);
		for (j=0;j<deg[i];j++) {
//			printf(" %d",sousedi[i][j]);
		}
//		printf("\n");
	}

	color[1] = 1;
	color[2] = 2;
	rekuCount(1,2);
	rekuCol(1,2);
	dump();
}



int main()
{
	int ncases;
	int i;
	scanf(" %d", &ncases);
	for (i=1; i<=ncases; i++) {
		printf("Case #%d: ", i);
		docase();
	}
	return 0;
}
