#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node_t *root;

char tbuf[10000];
int L;

int A;

char buf[100];

int has_feature(char **features, char *feature, int n) {
	int i;
	for(i = 0; i < n; ++ i)
		if(strcmp(features[i], feature) == 0)
			return 1;
	return 0;
}

char *skip(char *str) {
	while(*str == ' ' || *str == '\n')
		++ str;
	return str;
}

double calc(char *str, char **features, int fn) {
	int len = L;
	int i = 0;
	double p = 1.0, weight;
	char feature[100];
	int backup;

	int bracket = 0;

	while(i < len) {
		if(str[i] == ' ' || str[i] == '\n') ++ i;
		else if(str[i] == '(') {//step into a sub tree
			++ bracket;

			i = skip(str + i + 1) - str;
			sscanf(str + i, "%lf", &weight);
			p *= weight;
			for(; isdigit(str[i]) || str[i] == '.'; ++ i)
				;

			i = skip(str + i) - str;
			if(str[i] == ')') //leaf
				return p;
			//node
			sscanf(str + i, "%s", feature);
			i += strlen(feature);

			if(has_feature(features, feature, fn))
				continue;

			backup = bracket;
			for(; str[i] != ')' && str[i] != '('; ++ i)
				;
			do {
				if(str[i] == '(') ++ bracket;
				else if(str[i] == ')') -- bracket;
				++ i;
			} while(bracket != backup);
			i = skip(str + i + 1) - str;
		}
	}
}

int main() {
	int cases;
	int i, j;
	char **features = NULL;
	int fn;
	double res;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &cases);

	for(i = 1; i <= cases; ++ i) {
		scanf("%d", &L);
		gets(tbuf);

		j = 0;
		while(L --) {
			gets(tbuf + j);
			j += strlen(tbuf + j);
			tbuf[j ++] = ' ';
		}
		L = j;

		printf("Case #%d:\n", i);

		scanf("%d", &A);
		while(A --) {
			scanf("%s", buf);	//skip name
			scanf("%d", &fn);

			features = malloc(sizeof(char *) * fn);
			for(j = 0; j < fn; ++ j) {
				features[j] = malloc(sizeof(char) * 11);
				scanf("%s", features[j]);
			}

			res = calc(tbuf, features, fn);

			printf("%.7f\n", res);

			for(j = 0; j < fn; ++ j)
				free(features[j]);
			free(features);
		}
	}

	return 0;
}
