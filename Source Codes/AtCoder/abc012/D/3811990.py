import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

import numpy as np
from scipy.sparse.csgraph import floyd_warshall


n,m = li()


graph = np.inf * np.ones((n,n))

for i in range(m):
    a,b,t = li()
    graph[a-1][b-1] = t
    graph[b-1][a-1] = t
    
dist = floyd_warshall(graph, directed=False)

    
ans = 10**18
for i in range(n):
    ans = min(ans, max(dist[i]))
    
print(int(ans))