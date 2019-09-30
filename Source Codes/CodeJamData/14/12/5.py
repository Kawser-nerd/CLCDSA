#!/usr/bin/env python3

from collections import deque

T = int(input())
for case in range(1, T+1):
    N = int(input())
    edges = [tuple(int(i)-1 for i in input().split()) for i in range(N-1)]
    neigh = [[] for i in range(N)]
    for i, j in edges:
        neigh[i].append(j)
        neigh[j].append(i)
    ans = N
    for root in range(N):
        parent = [None for i in range(N)]
        children = [[] for i in range(N)]
        queue = deque([root])
        order = [root]
        while queue:
            cur = queue.popleft()
            for i in neigh[cur]:
                if parent[i] == None and i != root:
                    parent[i] = cur
                    children[cur].append(i)
                    queue.append(i)
                    order.append(i)
        order = list(reversed(order))
        size = [None for i in range(N)]
        cost = [None for i in range(N)]
        for i in order:
            c = children[i]
            d = len(c)
            size[i] = sum(size[j] for j in c) + 1
            if d == 0:
                cost[i] = 0
            elif d == 1:
                cost[i] = size[c[0]]
            elif d == 2:
                cost[i] = cost[c[0]] + cost[c[1]]
            else:
                cost[i] = size[i] - 1 - sum(sorted(size[j]-cost[j] for j in c)[-2:])
                #cost[i] = size[i] - 1 - max(size[j]+size[k]-cost[j]-cost[k] for j, k in combinations(c, 2))
        ans = min(ans, cost[root])
    print("Case #{}: {}".format(case, ans))

