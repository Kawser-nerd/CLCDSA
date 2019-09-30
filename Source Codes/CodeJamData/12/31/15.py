import operator
import itertools
import functools
import math
from collections import deque

def bfs(i):
    res = False
    visited = [0] * (N+1)
    q = deque([node[i]])
    while len(q):
        n = q.popleft()
        if visited[n[0]]:
            res = True
            return res
        else:
            visited[n[0]] = 1
        for x in n[1:]:
            q.append(node[x])
     
fn = open('1.in')
ofn = open('1.out', 'w')
TC = int(fn.readline())
for tc in range(TC):
    N = int(fn.readline().strip())
    node = [None] * (N+1)
    for i in range(1, N+1):
        r = map(int, fn.readline().strip().split())
        node[i] = [i] + r[1:]
    #print node
    
    for i in range(1, N+1):
        if bfs(i):
            print >>ofn, 'Case #{}: {}'.format(tc +1, 'Yes')
            break
    else:
        print >>ofn, 'Case #{}: {}'.format(tc +1, 'No')
        
    
    

    
    #print tc       
    #print >>ofn, 'Case #{}: {}'.format(tc +1, totalS)
        
        
