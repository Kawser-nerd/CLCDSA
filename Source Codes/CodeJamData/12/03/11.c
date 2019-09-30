#include <stdio.h>
#include <stdlib.h>

#define S int

typedef struct _set {
     S key;
     int size;
     int height;
     struct _set *child[2];
} set;

set *rotate(set *s, int l, int r);

int cmp_set(S a, S b)
{
     return a - b;
}

int empty(set *s)
{
     if (s == NULL) {
	  return 1;
     } else {
	  return 0;
     }
}

int size(set *s)
{
     if (s == NULL) {
	  return 0;
     } else {
	  return s->size;
     }
}

int height(set *s)
{
     if (s == NULL) {
	  return 0;
     } else {
	  return s->height;
     }
}

set *balance(set *s)
{
     int i;

     for (i = 0; i < 2; i++) {
	  if (height(s->child[!i]) - height(s->child[i]) < -1) {
	       if (height(s->child[i]->child[!i]) - height(s->child[i]->child[i]) > 0) {
		    s->child[i] = rotate(s->child[i], i, !i);
	       }

	       return rotate(s, !i, i);
	  }
     }

     if (s != NULL) {
	  if (height(s->child[0]) > height(s->child[1])) {
	       s->height = height(s->child[0]) + 1;
	  } else {
	       s->height = height(s->child[1]) + 1;
	  }

	  s->size = size(s->child[0]) + size(s->child[1]) + 1;
     }

     return s;
}

set *rotate(set *s, int l, int r)
{
     set *t = s->child[r];

     s->child[r] = t->child[l];
     t->child[l] = balance(s);

     if (s != NULL) s->size = size(s->child[0]) + size(s->child[1]) + 1;
     if (t != NULL) t->size = size(t->child[0]) + size(t->child[1]) + 1;

     return balance(t);
}

set *insert(set *s, S key)
{
     int x;

     if (s == NULL) {
	  set *tmp = malloc(sizeof(set));

	  tmp->key = key;
	  tmp->size = 1;
	  tmp->height = 1;
	  tmp->child[0] = NULL;
	  tmp->child[1] = NULL;

	  return tmp;
     }

     x = cmp_set(s->key, key);

     if (x == 0) return s;

     if (x > 0) {
	  s->child[0] = insert(s->child[0], key);
     } else {
	  s->child[1] = insert(s->child[1], key);
     }

     s->size++;

     return balance(s);
}

set *move_down(set *s, set *t)
{
     if (s == NULL) return t;

     s->child[1] = move_down(s->child[1], t);

     return balance(s);
}

int find(set *s, S key)
{
     int x;

     if (s == NULL) return 0;

     x = cmp_set(s->key, key);

     if (x == 0) return 1;

     if (x > 0) {
	  return find(s->child[0], key);
     } else {
	  return find(s->child[1], key);
     }
}

void clear(set *s)
{
	if (s == NULL) return;

	clear(s->child[0]);
	clear(s->child[1]);

	free(s);
}

int rank(set *s, int n)
{
     int m = size(s->child[0]);

     if (n < m) {
	  return rank(s->child[0], n);
     } else if (n == m) {
	  return s->key;
     } else {
	  return rank(s->child[1], n - m - 1);
     }
}

int c[2000001][10];
int p[2000001];

int main()
{
	int t, i, j, k;
	set *s = NULL;

	for (i = 1; i <= 2000000; i++) {
		int a[10];
		int x = i, y = 0;

		while (x) {
			a[y++] = x % 10;
			x /= 10;
		}

		for (j = 0; j < y - 1; j++) {
			int z = 0;
			
			if (a[j] == 0) continue;

			for (k = j; k >= 0; k--) {
				z *= 10;
				z += a[k];
			}

			for (k = y - 1; k > j; k--) {
				z *= 10;
				z += a[k];
			}

			if (z < i) s = insert(s, z);
		}

		for (j = size(s) - 1; j >= 0; j--) {
			c[i][p[i]++] = rank(s, j);
		}

		clear(s);
		s = NULL;
	}

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		int a, b, sum = 0;

		scanf("%d %d", &a, &b);

		for (j = a; j <= b; j++) {
			for (k = 0; k < p[j]; k++) {
				if (c[j][k] < a) break;

				sum++;
			}
		}

		printf("Case #%d: %d\n", i + 1, sum);
	}

	return 0;
}
