#! /usr/bin/python2.7

import networkx as nx

cache = {}
def find_sizes(amount, req):
    if (amount, req) in cache:
        return cache[(amount, req)]
    high_est = int(amount / (req * 0.9))
    low_est = max(int(amount / (req * 1.1)), 1)
    cache[(amount, req)] = set(i for i in xrange(low_est, high_est + 1) if req*0.9 <= float(amount)/i <= req*1.1)
    return cache[(amount, req)]

def solve(amounts, recepee, N, P):
    g = nx.Graph()
    root = "root"
    sink = "sink"
    g.add_node(root)
    g.add_node(sink)
    for i in xrange(P):
        if len(find_sizes(amounts[0][i], recepee[0])) > 0:
            g.add_edge(root, (0, i), capacity=1)
    for i in xrange(1, N):
        for j in xrange(P):
            for k in xrange(P):
                if len(find_sizes(amounts[i - 1][j], recepee[i-1]) & find_sizes(amounts[i][k], recepee[i])) > 0:
                    g.add_edge((i - 1, j), (i, k), capacity=1)
    for i in xrange(P):
        if len(find_sizes(amounts[N - 1][i], recepee[N - 1])) > 0:
            g.add_edge((N - 1, i), sink, capacity=1)
    return nx.maximum_flow_value(g, root, sink)    

import sys
f = sys.stdin
# f = open("q2_example.in")
T = int(f.readline())
for i in xrange(1, T + 1):
    N, P = map(int, f.readline().split())
    recepee = map(int, f.readline().split())
    amounts = []
    for j in xrange(N):
        amounts.append(map(int, f.readline().split()))
    print "Case #%d: %s" % (i, solve(amounts, recepee, N, P))