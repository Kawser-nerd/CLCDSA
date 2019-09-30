#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000000
char tree[SIZE];
char line[SIZE];
char features[1000][100];
int nfeatures;
int pos;


double prob(void) {
	pos++; // el (

	double valor = 0.0;
	sscanf(tree + pos, "%lf", &valor);

	while (isdigit(tree[pos])) pos++;
	while (tree[pos] == '.') pos++;
	while (isdigit(tree[pos])) pos++;

	if (tree[pos] == ')') {
		pos++; // el )
		return valor;
	}

	char f[100];
	int i = 0;
	while (tree[pos+i] != '(') {
		f[i] = tree[pos+i];
		i++;
	}
	f[i] = '\0';
	pos += i;

	double valor1 = prob();
	double valor2 = prob();

	double result = valor;

	for (i = 0; i < nfeatures; i++) {
		if (!strcmp(f, features[i])) {
			result *= valor1;
			break;
		}
	}


	if (i == nfeatures)
		result *= valor2;


	pos++; // el )
	return result;
}


int main(int argc, char *argv[]) {
	int ncases, c;
	scanf("%d", &ncases);
	for (c = 1; c <= ncases; c++) {
		int nlines;
		int i;
		scanf("%d\n", &nlines);

		tree[0] = '\0';
		for (i = 0; i < nlines; i++) {
			fgets(line,SIZE, stdin);
			line[strlen(line)-1] = ' ';
			strcat(tree, line);
		}

		strcpy(line, tree);
		int tree_size = 0;
		for (i = 0; line[i] != '\0'; i++) {
			if (line[i] != ' ' && line[i] != '\t') {
				tree[tree_size] = line[i];
				tree_size++;
			}
		}
		tree[tree_size] = '\0';

		printf("Case #%d:\n", c);

		int ntests;
		scanf("%d", &ntests);
		int t;
		for (t = 0; t < ntests; t++) {
			char tmp[1000];
			int n;
			scanf("%s %d", tmp, &n);

			for (i = 0; i < n; i++) {
				scanf("%s", features[i]);
			}

			nfeatures = n;
			pos = 0;
			printf("%lf\n", prob());
		}

	}
	return EXIT_SUCCESS;
}

