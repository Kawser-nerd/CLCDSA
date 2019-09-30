
def memoize(f):
    d = {}
    def wrap(*a):
        if a in d:
            return d[a]
        r = f(*a)
        d[a] = r
        return r
    return wrap

@memoize
def dp(p, l, i):
    assert (len(l) == p - 1)
    if all(x == 0 for x in l):
        return 0
    best = 0
    for j in range(len(l)):
        nl = list(l)
        if nl[j] == 0: continue
        nl[j] -= 1
        best = max(best, dp(p, tuple(nl), (i + j + 1) % p))
    if i == 0:
        best += 1
    return best

t = int(input())
for tc in range(t):
    print("Case #%d:" % (tc + 1), end = " ")
    n, p = map(int, input().split())
    gg = map(int, input().split())
    ll = [0] * p
    for x in gg:
        ll[x%p] += 1
    print(ll[0] + dp(p, tuple(ll[1:]), 0))
    
