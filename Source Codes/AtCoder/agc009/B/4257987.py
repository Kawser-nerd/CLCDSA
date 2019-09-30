import sys
sys.setrecursionlimit(10**6)
N = int(input())
tree = list(map(int, sys.stdin))
edges = [[] for _ in [0]*(N+1)]
for i, v in enumerate(tree, start=2):
    edges[v].append(i)


def rec(v):
    if not edges[v]:
        return 0

    depth = []
    for dest in edges[v]:
        depth.append(rec(dest))

    result = [i+d for i, d in enumerate(sorted(depth, reverse=True), start=1)]
    return max(result)


print(rec(1))