#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

#define	min(a, b)	(((a) < (b)) ? (a) : (b))
#define	max(a, b)	(((a) > (b)) ? (a) : (b))
#define	abs(x)		(((x) >= 0) ? (x) : -(x))

static int N;
static int M;

struct node {
	char name[101];
	struct node *pchild;
	struct node *psib;
};
typedef struct node node_t;

static node_t root = {"/", NULL, NULL};

static node_t *search_child(node_t *parent, char *name) {
	node_t *node;

	for (node = parent->pchild; node; node = node->psib) {
		if (0 == strcmp(node->name, name))
			return node;
	}
	return NULL;
}

static void add_child(node_t *pparent, node_t *pchild) {
	node_t *p = pparent->pchild;
	node_t *q = NULL;

	if (NULL == p) {
		pparent->pchild = pchild;
		return;
	}
	q = p->psib;
	while (NULL != q) {
		p = q;
		q = q->psib;
	}
	p->psib = pchild;
	pchild->psib = NULL;
}

static int add_dir(char *dir) {
	int i;
	int j;
	int flag;
	node_t *cur = &root;
	node_t *prev = &root;
	int cnt = 0;

	i = 1;
	while (i < strlen(dir)) {
		for (j = i; j < strlen(dir) && '/' != dir[j]; j++)
			;
		flag = 0;
		if ('/' == dir[j]) {
			dir[j] = '\0';
			flag = 1;
		}
		prev = cur;
		cur = search_child(cur, &dir[i]);
		if (NULL == cur) {
			cur = (node_t *)malloc(sizeof(node_t));
			strcpy(cur->name, &dir[i]);
			cur->pchild = cur->psib = NULL;
			add_child(prev, cur);
			cnt++;
		}
		if (flag)
			dir[j] = '/';
		i = j + 1;
	}
	return cnt;
}

static int parse_input(const char *infile) {
	FILE *fp;
	int T;
	int i;
	int j;
	node_t *node;
	char buf[201];
	int nmk;

	fp = fopen(infile, "r");
	fscanf(fp, "%d\n", &T);
	for (i = 1; i <= T; i++) {
		nmk = 0;
		root.pchild = root.psib = NULL;
		fscanf(fp, "%d %d\n", &N, &M);
		for (j = 0; j < N; j++) {
			fgets(buf, sizeof(buf), fp);
			buf[strlen(buf) - 1] = '\0';
			add_dir(buf);
		}
		for (j = 0; j < M; j++) {
			fgets(buf, sizeof(buf), fp);
			buf[strlen(buf) - 1] = '\0';
			nmk += add_dir(buf);
		}
		printf("Case #%d: %d\n", i, nmk);
	}
	fclose(fp);
	return 0;
}

int main(int argc, char *argv[]) {
	if (parse_input(argv[1]))
		exit(1);
	return 0;
}
