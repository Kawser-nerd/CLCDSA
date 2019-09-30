def solve():
    n = int(raw_input())
    df, ds = {}, {}
    ef, es = [], []
    for i in xrange(n):
        f, s = raw_input().split()
        if f not in df:
            j = len(df)
            df[f] = j
            ef.append([])
        if s not in ds:
            j = len(ds)
            ds[s] = j
            es.append([])
        f, s = df[f], ds[s]
        ef[f].append(s)
        es[s].append(f)
    m = len(ef)
    pairf = [None] * m
    pairs = [None] * len(es)
    def dfs(v):
        done[v] = 1
        for x in ef[v]:
            w = pairs[x]
            if w is None or (done[w] is None and dfs(w)):
                pairf[v] = x
                pairs[x] = v
                return 1
        return 0
    res = 0
    for i in xrange(m):
        done = [None] * m
        res += dfs(i)
    return n - m - len(es) + res

T = int(raw_input())
for t in xrange(T):
    print "Case #%d:" % (t + 1), solve()
