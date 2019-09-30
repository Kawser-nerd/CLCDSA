#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000

struct tree_node
{
	struct tree_node *left, *right;
	long long value;
	int size;
} *tree_root, *tree_pool_cur, tree_pool[MAXN], **tree_stack_head, *tree_stack[MAXN];

int E, R, N;
long long ans = 0;

void update_size( struct tree_node *root)
{
	int left = root->left ? root->left->size : 0;
	int right = root->right ? root->right->size : 0;
	root->size = left + right + 1;
}

void walk_down( struct tree_node *root, long long init, long long last)
{
	long long left_size = root->left ? root->left->size : 0;
	long long right_size = root->right ? root->right->size : 0;
	init = init > E ? E : init;
	last = last < 0 ? 0 : last;

	long long before = init + left_size * R;
	before = before > E ? E : before;
	long long after = last - right_size * R;
	after = after < 0 ? 0 : after;

	if ( before < after)
	{
		fprintf( stderr, "WRONG PARA AT: %lld!\n", root->value);
		fprintf( stderr, "AT %lld %d %d %lld %d\n", root->value, before, after, ans, root->size);
	}

	ans += ( before - after) * root->value;
//	fprintf( stderr, "AT %lld %d %d %lld %d\n", root->value, before, after, ans, root->size);
	if ( root->left)
	{
//		printf( "left to %lld\n", root->left->value);
		walk_down( root->left, init, before - R);
	}
	if ( root->right)
	{
//		printf( "right to %lld\n", root->right->value);
		walk_down( root->right, after + R, last);
	}
}

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		tree_pool_cur = tree_pool;
		tree_stack_head = tree_stack - 1;
		scanf("%d %d %d", &E, &R, &N);

		int i;
		for ( i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);

			tree_pool_cur->value = value;
			tree_pool_cur->size = 1;
			tree_pool_cur->left = tree_pool_cur->right = NULL;

			while ( tree_stack_head >= tree_stack && (*tree_stack_head)->value < value)
			{
				tree_pool_cur->left = *tree_stack_head;
				update_size( *tree_stack_head);
				--tree_stack_head;
			}
			if ( tree_stack_head >= tree_stack)
			{
				(*tree_stack_head)->right = tree_pool_cur;
			}
			*++tree_stack_head = tree_pool_cur++;
		}
		struct tree_node **leg;
		for ( leg = tree_stack_head; leg >= tree_stack; leg--)
		{
			update_size( *leg);
		}

		tree_root = *tree_stack;
		ans = 0;
		walk_down( tree_root, E, 0);

		printf("Case #%d: %lld\n", cases + 1, ans);
	}

	return 0;
}
