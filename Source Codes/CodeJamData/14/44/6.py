#!/usr/bin/python

from itertools import product

MOD = 1000000007

def get_node_count(strings):
    prefixes = set()
    for s in strings:
        for i in range(len(s)+1):
            prefixes.add(s[:i])
    return len(prefixes)

T = int(raw_input().strip())

for t in range(T):
    M, N = map(int, raw_input().strip().split())
    S = []
    for i in range(M):
        S.append(raw_input().strip())

    worst = 0
    ways = 0

    for sharding in product(*(list(range(N)) for s in S)):
        servers = [[] for x in range(N)]
        for i, server in enumerate(sharding):
            servers[server].append(S[i])

        good = True
        for s in servers:
            if not s:
                good = False
                break
        if not good:
            continue

        node_count = 0
        for server in servers:
            node_count += get_node_count(server)

        if node_count == worst:
            ways += 1
        elif node_count > worst:
            worst = node_count
            ways = 1

    print 'Case #{}: {} {}'.format(t+1, worst, ways % MOD)
