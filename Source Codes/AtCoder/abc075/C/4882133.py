import numpy as np
import queue
n,m = map(int,input().split())

V = np.zeros((n+1,n+1),dtype=bool)
E = []
for i in range(m):
    a,b = map(int,input().split())
    V[a][b] = True
    V[b][a] = True
    E.append((a,b))
def BFS(x,y):
    mark = [False]*(n+1)
    q = queue.Queue()
    q.put(x)
    while not q.empty():
        p = q.get()
        if p == y:
            return True
        mark[p] = True
        for i in range(1,n+1):
            if V[p][i] and not mark[i]:
                q.put(i)
    return False
res = 0

for a,b in E:
    V[a][b] = False
    V[b][a] = False
    if not BFS(a,b):
        res+=1

    V[a][b] = True
    V[b][a] = True
print(res)