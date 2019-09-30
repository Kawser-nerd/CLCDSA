#include <stdio.h>

typedef struct list_t {
	struct list_t *next;
	struct list_t *prev;
	void *value;
} list_t;

/* void list_init(list_t *) */
#define list_init(list) do {              \
	(list)->next = (list)->prev = (list); \
	(list)->value = 0;                    \
} while (0)

#define list_add_last(head, node) ( \
	(node)->prev = (head)->prev,    \
	(node)->next = (head),          \
	(head)->prev->next = (node),    \
	(head)->prev = (node))

/* void list_remove(list_t *node) */
#define list_remove(node) (            \
	(node)->next->prev = (node)->prev, \
	(node)->prev->next = (node)->next)




#define MAX_K 5000


typedef struct {
	list_t list[1];
	int value;
} deck_t;


void calc(deck_t *deck, int n)
{
	list_t *node, *tmp;
	int i, v;
	list_init(deck[0].list);
	for (i = 1; i < n; i++)
		list_add_last(deck[0].list, deck[i].list);

	node = deck[0].list;
	for (v = 1; v <= n; v++)
	{
		for (i = 1;
			i < v;
			i++, node = node->next);
		tmp = node->next;
		list_remove(node);
		((deck_t *)node)->value = v;
		node = tmp;
	}
#if 0
	for (i = 1; i <= n; i++)
		printf("%d ", deck[i].value);
	printf("\n");
#endif
}


int main(void)
{
	deck_t deck[MAX_K+1];
	int t, T, K, n, i, d;

	scanf("%d ", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d", &K);
		calc(deck, K);
		scanf("%d", &n);

		printf("Case #%d:", t);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &d);
			printf(" %d", deck[d-1].value);
		}
		printf("\n");
	}

	return 0;
}
