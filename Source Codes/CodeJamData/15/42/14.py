tests = int(input())

EPS = 1e-12

for t in range(1, tests + 1):
    s = input().split()
    n, (V, X) = int(s[0]), map(float, s[1:])
    r, c = [], []
    for i in range(n):
        ri, ci = map(float, input().split())
        r.append(ri)
        c.append(ci)

    def take(a):
        sumvx, sumv = 0., 0.
        remain = V
        for x, v in a:
            here = min(v, remain)
            remain -= here
            sumvx += x * here
            sumv += here
        return sumvx / sumv
        

    def can(time):
        v = [ri * time for ri in r]
        if sum(v) < V:
            return False
        a = sorted(list(zip(c, v)))
        tmin = take(a)
        tmax = take(a[::-1])
        return tmin - EPS <= X <= tmax + EPS
        
    left, right = 0., 1e15
    for i in range(200):
        mid = (left + right) / 2
        if can(mid):
            right = mid
        else:
            left = mid
    possible = any(ci <= X for ci in c) and any(ci >= X for ci in c)
    if not possible:
        print('Case #{}: IMPOSSIBLE'.format(t))
    else:
        print('Case #{}: {:.15f}'.format(t, right))
