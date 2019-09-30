def inpl(): return [int(i) for i in input().split()]
def find(x):
    if par[x] == x:
        return x
    else:
        par[x],dist[x] = find(par[x]),dist[x]+dist[par[x]]
        return par[x]
N, M = inpl()
par = list(range(N+1))
dist = [0 for _ in range(N+1)]

for _ in range(M):
    l, r, d = inpl()
    fl = find(l)
    fr = find(r)
    if fl != fr:
        par[fr] = fl
        dist[fr] = d + dist[l] - dist[r]
    elif d + dist[l] - dist[r] != 0:
        print('No')
        break
else:
    print('Yes')