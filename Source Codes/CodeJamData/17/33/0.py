tnum = int(raw_input())

def f(ps, k):
    dyn = [0. for _ in range(k+1)]
    dyn[0] = 1.
    for p in ps:
        tdyn = dyn
        dyn = [(1-p)*tdyn[i]+p*tdyn[max(i-1, 0)] for i in range(k+1)]
    return dyn[k]

def g(ps, k, u):
    ps = sorted(ps)
    ret = f(ps, k)
    for i in range(len(ps)):
        SS = 0.
        MM = 0.
        for j in range(i, len(ps)):
            SS += ps[j]
            MM = max(MM, ps[j])
            t = (SS+u)/(j-i+1)
            if t<MM:
                continue
            if j+1<len(ps) and t>ps[j+1]-1e-5:
                continue
            t = min(t, 1.)
            ret = max(ret, f(ps[:i]+[t]*(j-i+1)+ps[j+1:], k))
    return ret

for ti in range(tnum):
    n, k = [int(x) for x in raw_input().split()]
    u = float(raw_input().strip())
    ps = [float(x) for x in raw_input().split()]
    ps = sorted(ps)
    ans = g(ps, k, u)
    while (len(ps)>0):
        if ps[-1]+u<1.:
            break
        u -= 1.-ps[-1]
        k = max(0, k-1)
        ps = ps[:-1]
        ans = max(ans, g(ps, k, u))
    print 'Case #{}: {:.9f}'.format(ti+1, ans)
