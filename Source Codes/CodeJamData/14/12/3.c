#include <stdio.h>
//#define debug

int goToBottom(int stackAt, int parent, int tree[][1000], int * nodes, int * stack)
{
	int from = stack[stackAt];

	while (1)
	{
		if (!nodes[from]) return stackAt;
	
		else if (tree[from][0] != parent)
		{
			parent = from;
			from = tree[from][0];
		}
		
		else if (nodes[from] == 1) return stackAt;
		
		else
		{
			parent = from;
			from = tree[from][1];
		}
		
		stack[++stackAt] = from;
	}
}

int main()
{
	int T;
	
	scanf("%d", &T);
	
	for (int Q = 1; Q <= T; Q++)
	{
		int N;
	
		scanf("%d", &N);
		
		int nodes[N];
		
		// tree is a neighbour list
		
		int tree[N][1000];
		
		for (int i = 0; i < N; i++)
		{
			nodes[i] = 0;
		}
		
		for (int i = 1; i < N; i++)
		{
			int x, y;
			
			scanf("%d %d", &x, &y);
			
			x--;
			y--;
			
			tree[x][nodes[x]] = y;
			tree[y][nodes[y]] = x;
			
			nodes[x]++;
			nodes[y]++;
		}
		
#ifdef debug
		for (int i = 0; i < N; i++)
		{
			printf("%d |", i + 1);
			
			for (int j = 0; j < nodes[i]; j++)
			{
				printf(" %d", tree[i][j] + 1);
			}
			
			putchar('\n');
		}
		
		putchar('\n');
#endif
		
		// for each node, assume it is the root
		// then visit nodes from the bottom up (!), pruning nodes that are only children
		// and lightest superfluous nodes
		
		int leastPruned = N + 1;
		
		for (int root = 0; root < N; root++)
		{
			int pruned = 0;
			
			int stack[N];
			int weight[N];
			stack[0] = root;
			
			int stackAt = goToBottom(0, -1, tree, nodes, stack);
			
#ifdef debug
			printf("trying %d as root |", root + 1);
			
			for (int STACK = 0; STACK <= stackAt; STACK++) printf(" %d", stack[STACK] + 1); putchar('\n');
#endif
			
			while (stackAt)
			{
				int visiting = stack[stackAt],
					parent = stack[stackAt - 1];
					
				weight[visiting] = 1;
					
				// need to do some selective lopping based on weight
				
				// lop stuff off
					
				int heaviest = 0;
				int nextHeaviest = 0;
				
				for (int i = 0; i < nodes[visiting]; i++)
				{
					if (tree[visiting][i] == parent) continue;
						
					int thisWeight = weight[tree[visiting][i]];
						
					if (thisWeight > heaviest)
					{
						nextHeaviest = heaviest;
						heaviest = thisWeight;
					}
							
					else if (thisWeight > nextHeaviest)
					{
						nextHeaviest = thisWeight;
					}
				}
				
				if (heaviest && nextHeaviest) 
				{
					weight[visiting] += heaviest + nextHeaviest;
				}
				
#ifdef debug
				printf("visiting %d with weight %d |", visiting + 1, weight[visiting]);
				
				for (int STACK = 0; STACK <= stackAt; STACK++) printf(" %d", stack[STACK] + 1); putchar('\n');
#endif
				
				// decide where to go next; either next sibling or parent
				
				for (int i = 0; i < nodes[parent]; i++)
				{
					if (stackAt > 1 && stack[stackAt - 2] == tree[parent][i]) continue;
					
					if (tree[parent][i] == visiting)
					{
						i++;
					
						if (i < nodes[parent] && stackAt > 1 && stack[stackAt - 2] == tree[parent][i])
						{
							i++;
						}
						
						if (i < nodes[parent])
						{
							stack[stackAt] = tree[parent][i];
							stackAt = goToBottom(stackAt, parent, tree, nodes, stack);
						}
						else
						{
							stackAt--;
						}
						
						break;
					}
				}
			}
			
			// now you're back at the root! determine its weight and compare to number of nodes
			
			weight[root] = 1;
			
			int heaviest = 0;
			int nextHeaviest = 0;
				
			for (int i = 0; i < nodes[root]; i++)
			{
				int thisWeight = weight[tree[root][i]];
					
				if (thisWeight > heaviest)
				{
					nextHeaviest = heaviest;
					heaviest = thisWeight;
				}
							
				else if (thisWeight > nextHeaviest)
				{
					nextHeaviest = thisWeight;
				}
			}
			
			if (heaviest && nextHeaviest)
			{
				weight[root] += heaviest + nextHeaviest;
			}
			
#ifdef debug
			printf("had to prune %d for root %d\n\n", N - weight[root], root + 1);
#endif
			
			if (N - weight[root] < leastPruned)
			{
				leastPruned = N - weight[root];
			}
		}
		
		printf("Case #%d: %d\n", Q, leastPruned);
	}
}