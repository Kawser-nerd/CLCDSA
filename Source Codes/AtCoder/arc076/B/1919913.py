# -*- coding: utf-8 -*-
def inpl(): return tuple(map(int, input().split()))

n = int(input())
X = []
Y = []
for i in range(n):
    x, y = inpl()
    X.append((x, i))
    Y.append((y, i))

X = sorted(X, key = lambda x: x[0])
Y = sorted(Y, key = lambda y: y[0])

G = [[] for _ in range(n)]
edges = []
for i in range(n-1):
    edges.append((X[i][1], X[i+1][1], abs(X[i][0] - X[i+1][0])))
    edges.append((Y[i][1], Y[i+1][1], abs(Y[i][0] - Y[i+1][0])))

edges = sorted(edges, key = lambda e: e[2])

tree = [[-1, 1] for _ in range(n)]

def find(i):
    if tree[i][0] == -1:
        group = i
    else:
        group = find(tree[i][0])    
    return group
  
def unite(x, y):
    px = find(x)
    py = find(y)
      
    if tree[px][1] == tree[py][1]: # rank is same
        tree[py][0] = px
        tree[px][1] += 1
    else:
        if tree[px][1] < tree[py][1]:
            px, py = py, px
        tree[py][0] = px

res = 0

for s, t, w in edges:
    if find(s) != find(t):
        unite(s, t)
        res += w
print(res)