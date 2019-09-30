def memoize(f):
    d = {}
    def wrap(*a):
        if a in d:
            return d[a]
        d[a] = f(*a)
        return d[a]
    return wrap

def solve(r, p, s, priorities):
    n = r + p + s
    if n == 1:
        if r == 1:
            return [0]
        elif p == 1:
            return [1]
        elif s == 1:
            return [2]
        assert False
    assert n % 2 == 0
    if r + p < s or r + s < p or s + p < r:
        return None
    low = r + p - s
    if low % 2 != 0:
        return None
    a = low // 2
    w = list(map(lambda r: sorted(r, key = lambda u: priorities[u]), [[0, 2], [1, 0], [1, 2]]))
    rr = [(list(map(lambda u: priorities[u], z)), i) for (i, z) in enumerate(w)]
    rr.sort()
    nn = [i for z, i in rr]
    nprio = sorted([0, 1, 2], key = lambda u: nn[u])
    l = solve(r - a, a, p - a, nprio)
    if l == None:
        return None
    ll = []
    for x in l:
        ll += w[x]
    return ll

def print_solution(l):
    if l == None:
        print("IMPOSSIBLE")
        return
    print("".join("RPS"[x] for x in l))

t = int(input())
for i in range(t):
    print("Case #%s:" % (i + 1), end = " ")
    _, r, p, s = map(int, input().split())
    print_solution(solve(r, p, s, [1, 0, 2]))
