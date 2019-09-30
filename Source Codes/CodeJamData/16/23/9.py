#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''

def case():
    N, = ints()
    titles = [line().split() for i in range(N)]
    for t in titles:
        a, b = t
        t[:] = ['a:' + a, 'b:'+b]
    pprint(titles)

    # Max flow on possibly fake titles
    source = 0
    sink = 1
    node2id = dict(source=source, sink=sink)
    wordcounts = {}
    for a, b in titles:
        for x in a, b:
            node2id.setdefault(x, len(node2id))
            wordcounts.setdefault(x, 0)
            wordcounts[x] += 1
    pprint(node2id)
    pprint(wordcounts)

    N = len(node2id)
    capacity = [[0] * N for i in range(N)]
    for word, count in wordcounts.items():
        if word.startswith('a'):
            capacity[source][node2id[word]] = count-1
        else:
            capacity[node2id[word]][sink] = count-1
    for a, b in titles:
        assert capacity[node2id[a]][node2id[b]] == 0
        capacity[node2id[a]][node2id[b]] = 1

    def dfs(pos, visited):
        if pos == sink:
            return True
        for t in range(N):
            if capacity[pos][t]:
                if t in visited: continue
                visited.add(t)
                capacity[pos][t] -= 1
                capacity[t][pos] += 1
                res = dfs(t, visited)
                if res:
                    return res
                capacity[t][pos] -= 1
                capacity[pos][t] += 1

    n = 0
    while True:
        res = dfs(source, set())
        if not res: break
        n += 1
    return n

if __name__ == '__main__':
    main()
