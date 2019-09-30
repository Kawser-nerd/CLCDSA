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

from collections import deque

n,m = li()

graph = [[] for _ in range(n)]
for _ in range(m):
    a,b = li_()
    graph[a].append(b)
    graph[b].append(a)
    
    path = deque([a,b])
    
path_set = set(path)

ed = b

satisfied = False
while not satisfied:
    
    satisfied = True
    
    for nex in graph[ed]:
        if nex in path_set:
            continue
        else:
            path_set.add(nex)
            path.append(nex)
            ed = nex
            satisfied = False
            break

    
ed = a

satisfied = False
while not satisfied:
    satisfied = True
    
    for nex in graph[ed]:
        if nex in path_set:
            continue
        else:
            path_set.add(nex)
            path.appendleft(nex)
            ed = nex
            satisfied = False
            break 
    
path = [pi+1 for pi in path]
    
print(len(path))
print(*path)