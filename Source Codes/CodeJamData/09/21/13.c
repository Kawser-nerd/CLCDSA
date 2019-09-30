#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	double weight;
	char * feature;
	struct node * st, * dr;
};

typedef struct node Node;

char buffer1[8100];
Node * tree;
char * buffer;

int n;
char crtn[20];
char features[100][20];
double res;


Node * createTree()
{
	char name[20];
	int i = 0;
	while (*buffer == ' ' || *buffer == '\n')
		buffer++;
	if (buffer[0] != '(')
		return NULL;
	buffer++;
	Node * newN = (Node*) malloc(sizeof(Node));
	double w;
	sscanf(buffer, "%lf", &w);
	newN->weight = w;
	char * openB = strchr(buffer, '(');
	char * clB = strchr(buffer, ')');
	if (openB != NULL && openB < clB) { // has children
		while (!isalpha(*buffer))
			buffer++;
		i = 0;
		while (isalpha(*buffer)) {
			name[i++] = *buffer;
			buffer++;
		}
		name[i] = 0;
		newN->feature = strdup(name);
		buffer = openB;
		newN->st = createTree();
		newN->dr = createTree();
	}
	else {
		newN->feature = NULL;
		newN->st = NULL;
		newN->dr = NULL;
	}
	buffer = strchr(buffer, ')') + 1;
	return newN;
}

void printTree(Node * tree, int sp)
{
	if (tree == NULL)
		return;
	printf("%*c %lf ", sp, ' ', tree->weight);
	if (tree->feature != NULL) {
		printf("%s\n", tree->feature);
		printTree(tree->st, sp + 2);
		printTree(tree->dr, sp + 2);
	}
	else
		printf("\n");
}


void readdata()
{
	char auxbuf[81];
	int l, i;
	scanf("%d\n", &l);
	buffer1[0] = 0;
	for (i = 0; i < l; i++) {
		fgets(auxbuf, 80, stdin);
		strcat(buffer1, auxbuf);
	}
	buffer = buffer1;
	tree = createTree();
}

void search(Node * tree)
{
	res *= tree->weight;
	if (tree->feature == NULL)
		return;
	int ok = 0;
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(tree->feature, features[i]) == 0) {
			ok = 1;
			break;
		}
	if (ok)
		search(tree->st);
	else
		search(tree->dr);
}

void solve()
{
	int nr, i, j;
	scanf("%d\n", &nr);
	for (i = 0; i < nr; i++) {
		scanf("%s", crtn);
		scanf("%d", &n);
		for (j = 0; j < n; j++)
			scanf("%s", features[j]);
		scanf("\n");
		res = 1;
		search(tree);
		printf("%.7lf\n", res);
	}
}

int main(int argc, char * argv[])
{
	freopen(argv[1], "rt", stdin);
	freopen(argv[2], "wt", stdout);

	int t, it;
	scanf("%d", &t);
	for (it = 1; it <= t; it++) {
		readdata();
	//	printTree(tree, 0);
		printf("Case #%d:\n", it);
		solve();
	}
	return 0;

}
