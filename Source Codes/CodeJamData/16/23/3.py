import sys
from collections import Counter,defaultdict
import itertools
# networkx downloadable from https://networkx.github.io/
import networkx as nx

def go(A):
    A=[('0'+a,'1'+b) for a,b in A]
    G = nx.DiGraph()
    first = set()
    second = set()
    for a,b in A:
        G.add_edge(a,b,capacity=1)
        first.add(a)
        second.add(b)
    for f in first:
        G.add_edge('start',f,capacity=1)
    for s in second:
        G.add_edge(s,'dest',capacity=1)
    _,F = nx.maximum_flow(G, 'start', 'dest')
    count = 0
    for a,b in A:
        if F[a][b]>0:
            if a in first:
                first.remove(a)
            if b in second:
                second.remove(b)
            count += 1
    return len(A) - (len(first)+len(second)+count)

#print 'remove this'
#sys.stdin=open('datac.txt')
#sys.stdin=open(r'c:\Users\Peter\Downloads\A-small-attempt0.in')

T=input()
for t in range(1,T+1):
    n=input()
    A=[raw_input().split() for i in range(n)]
    print "Case #{}: {}".format(t,go(A))
