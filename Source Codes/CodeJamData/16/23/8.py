import sys
import random
import re
from itertools import permutations

import networkx as nx


def solve():
    n = int(sys.stdin.readline())
    topics = []
    for i in xrange(n):
        topics.append(sys.stdin.readline().split())
    
    left = set()
    right = set()
    
    for a, b in topics:
        left.add(a)
        right.add(b)
    
    G = nx.DiGraph()
    for a, b in topics:
        G.add_edges_from([((a,0), (b,1), {'capacity': 1, 'weight': 1})])
    
    for a in left:
        G.add_edges_from([(0, (a,0), {'capacity': 1, 'weight': 0})])
    for b in right:
        G.add_edges_from([((b,1), 1, {'capacity': 1, 'weight': 0})])
    
    mincostFlow = nx.max_flow_min_cost(G, 0, 1)
    mincost = nx.cost_of_flow(G, mincostFlow)
    # print mincost
    
    needed_arcs = len(left) + len(right) - mincost
    
    faked = len(topics) - needed_arcs
    print faked
    


if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in xrange(t):
        print "Case #%d:" % (i+1),
        solve()

