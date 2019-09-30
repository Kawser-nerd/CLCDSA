import sys
sys.setrecursionlimit(200000)

N = int(input())
edges = [[] for _ in [0]*N]
for i, v in enumerate(map(int, sys.stdin), start=1):
    edges[i].append(v)
    edges[v].append(i)

balance = [0]*N

def rec(v, prev):
    total, max_count = 0, 0
    for to_v in edges[v]:
        if to_v != prev:
            part = rec(to_v, v)
            total, max_count = total+part, max(max_count, part)
    balance[v] = max(max_count, N-1-total)
    return total + 1


rec(0, -1)
print(*balance, sep="\n")