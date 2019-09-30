import sys
sys.setrecursionlimit(10**7)

N = int(input())
src = [tuple(map(int,input().split())) for i in range(N-1)]
MOD = 10**9+7
es = [[] for i in range(N)]
for a,b in src:
    a,b = a-1,b-1
    es[a].append(b)
    es[b].append(a)

mw = [None]*N
mb = [None]*N

def rec(v,c,p=-1):
    if c:
        if mb[v] is not None: return mb[v]
    else:
        if mw[v] is not None: return mw[v]
    ret = 1
    for to in es[v]:
        if to==p: continue
        tmp = rec(to,0,v)
        if c==0:
            tmp += rec(to,1,v)
        ret *= tmp
        ret %= MOD
    if c:
        mb[v] = ret
    else:
        mw[v] = ret
    return ret

print((rec(0,0) + rec(0,1))%MOD)