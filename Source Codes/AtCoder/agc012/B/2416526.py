import sys
sys.setrecursionlimit(101010)

N,M = map(int,input().split())
es = [[] for i in range(N)]
for i in range(M):
    a,b = map(lambda x:int(x)-1,input().split())
    es[a].append(b)
    es[b].append(a)
Q = int(input())
qs = [tuple(map(int,input().split())) for i in range(Q)]

mem = [[0,-1] for i in range(N)] # [color,depth] for v
def paint(v,d,c):
    mc,md = mem[v]
    if d <= md: return
    mem[v] = [mc if mc else c, d]
    if d == 0: return
    for to in es[v]:
        paint(to,d-1,c)

for v,d,c in reversed(qs):
    paint(v-1,d,c)
for c,d in mem:
    print(c)