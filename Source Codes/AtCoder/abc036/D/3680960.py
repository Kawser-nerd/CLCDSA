# time complexity: O(N)
# space compleixy: O(N)

import sys
fin = sys.stdin.readline
from queue import deque


def bfs(s, adj):
    parent = [None] * len(adj)
    level = [None] * len(adj)
    level[s] = 0
    queue = deque([s])
    while queue:
        node = queue.popleft()
        for neighbor in adj[node]:
            if level[neighbor] is None:
                parent[neighbor] = node
                level[neighbor] = level[node] + 1
                queue.append(neighbor)
    return parent, level


MOD = 10**9 + 7
N = int(fin())
adj = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b = [int(elem) - 1 for elem in fin().split()]
    adj[a].append(b)
    adj[b].append(a)

root = 0
parent, level = bfs(root, adj)
max_level = max(level)
level_to_nodes = [[] for _ in range(max_level + 1)]
for node, l in enumerate(level):
    level_to_nodes[l].append(node)

combination_total = [0] * N
combination_white = [0] * N
for deepest_node in level_to_nodes[-1]:
    combination_total[deepest_node] = 2
    combination_white[deepest_node] = 1
for current_level in reversed(range(max_level)):
    nodes_this_level = level_to_nodes[current_level]
    for node in nodes_this_level:
        combination_total[node] = 1
        combination_white[node] = 1
        for child in adj[node]:
            if child != parent[node]:
                combination_white[node] *= combination_total[child]
                combination_total[node] *= combination_white[child]
                combination_white[node] %= MOD
                combination_total[node] %= MOD
        combination_total[node] += combination_white[node]
        combination_total[node] %= MOD
print(combination_total[root])