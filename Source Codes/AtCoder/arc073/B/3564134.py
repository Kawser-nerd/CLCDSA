def inpl(): return [int(i) for i in input().split()]

N,W = inpl()
H = {0: 0}
for i in range(N):
    w, v = inpl()
    for iw, iv in H.copy().items():
        if iw+w <=W:
            H[iw + w] = max(H.get(iw + w, 0),iv+v)
ans = 0
for aw,av in H.items():
    ans = max(ans,av)

print(ans)