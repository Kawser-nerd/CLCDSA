import sys
from collections import defaultdict, deque

N = int(input())
graph = defaultdict(list)

for a, b, c in (l.split() for l in sys.stdin):
    graph[a].append((c, int(b)))
    graph[c].append((a, 1/int(b)))

result_value, result_from, result_to = 0, "", ""
for sv in graph.keys():
    dq = deque([(-1, sv)])
    append, popleft = dq.append, dq.popleft
    visited = defaultdict(int)
    visited[sv] = 1
    while dq:
        cost, v = popleft()
        if result_value > cost:
            result_value, result_from, result_to = cost, sv, v
        for to_v, to_cost in graph[v]:
            if not visited[to_v]:
                visited[to_v] = 1
                new_cost = cost*to_cost
                append((new_cost, to_v))

print("1{}={}{}".format(result_from, round(-result_value), result_to))