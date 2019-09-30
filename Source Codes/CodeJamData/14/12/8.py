from collections import defaultdict
from heapq import nlargest

def maxSize(adj, node, parent):
    children = adj[node] - {parent}
    if len(children) == 1: return 1
    return sum(nlargest(2, (maxSize(adj, child, node) for child in children))) + 1

for t in range(int(input())):
    N = int(input())
    adj = defaultdict(set)
    for _ in range(N-1):
        a, b = map(int, input().split())
        adj[a].add(b)
        adj[b].add(a)
    result = N - max(maxSize(adj, root, None) for root in range(1, N+1))
    assert 0 <= result <= N
    print('Case #{}: {}'.format(t+1, result))
