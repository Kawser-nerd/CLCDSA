#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXM 100
#define MAXN 100
#define MAXL 100
#define MAXNODES ((MAXL/2)*(MAXN+MAXM)+1)

typedef struct node {
	char *name;
	unsigned num;
	unsigned child[MAXNODES];
} node;

node tree[MAXNODES];
unsigned int num;


void dump () {
	unsigned int i, j;
	for (i = 0; i < num; i++) {
		printf ("%u %s (", i, tree[i].name);
		for (j = 0; j < tree[i].num; j++) {
			printf ("%u ", tree[i].child[j]);
		}
		printf (")\n");
	}
}

unsigned insert (char *name[], unsigned n) {
	unsigned i, j, res = 0;
	unsigned pos = 0;
	int found;
	
	for (i = 0; i < n; i++) {
		found = 0;
		for (j = 0; j < tree[pos].num; j++) {
			if (strcmp (name[i], tree[tree[pos].child[j]].name) == 0) {
				pos = tree[pos].child[j];
				found = 1;
				break;
			}
		}
		if (!found) {
			tree[num].name = name[i];
			tree[num].num = 0;
			
			tree[pos].child[tree[pos].num] = num;
			tree[pos].num++;
			
			pos = num;
			num++;
			res++;
		}
	}
	
	return res;
}

void doit () {
	unsigned n, m, i, j, count, res = 0;
	char bufs[MAXN+MAXM][MAXL+2];
	char *tokens[MAXL];
	
	/* init tree */
	num = 1;
	tree[0].num = 0;
	tree[0].name = "";
	
	/* input */
	scanf ("%u %u ", &n, &m);
	
	/* insert stuff already there */
	for (i = 0; i < n; i++) {
		scanf ("%s", bufs[i]);
		
		count = 0;
		for (j = 0; bufs[i][j] != '\n' && bufs[i][j] != '\0'; j++) {
			if (bufs[i][j] == '/') {
				bufs[i][j] = '\0';
				tokens[count] = &bufs[i][j+1];
				count++;
			}
		}
		
		insert (tokens, count);
		/*dump (); */
	}
	
	/* insert new stuff */
	for (i = n; i < n+m; i++) {
		scanf ("%s", bufs[i]);
		
		count = 0;
		for (j = 0; bufs[i][j] != '\n' && bufs[i][j] != '\0'; j++) {
			if (bufs[i][j] == '/') {
				bufs[i][j] = '\0';
				tokens[count] = &bufs[i][j+1];
				count++;
			}
		}
		
		res += insert (tokens, count);
		/*dump ();*/
	}
	
	printf ("%u\n", res);
}

int main () {
	unsigned i, t;
	
	scanf ("%u ", &t);
	for (i = 1; i <= t; i++) {
		printf ("Case #%u: ", i);
		doit ();
	}
	
	return 0;
}
