import sys

input = sys.stdin.readline
inf = float("inf")

n,m = map(int,input().split())
edge = [[] for i in range(n+1)]

for i in range(m):
    a,b = map(int,input().split())
    edge[a].append(b)
    edge[b].append(a)

def f(x):
    for e in edge[x]:
        if used[e]:
            continue
        else:
            return e
    return -1
used = [False]*(n+1)
used[1] = used[edge[1][0]] = True
path = [1,edge[1][0]]

while True:
    con = f(path[-1])
    if con == -1:
        break
    else:
        path.append(con)
        used[con] = True
path = path[::-1]
while True:
    con = f(path[-1])
    if con == -1:
        break
    else:
        path.append(con)
        used[con] = True
print(len(path))
for e in path:
    print(e,end = " ")