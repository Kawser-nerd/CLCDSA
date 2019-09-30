def solve(lgn, p):
    n = 2 ** lgn
    if p == 1: return 0, 0
    if p == n: return n-1, n-1
    q = always = 0
    chunk = n / 2
    add = 2
    while q + chunk < p:
        # print 'q', q, 'chunk', chunk
        q += chunk
        chunk /= 2
        always += add
        add *= 2

    q = 0
    chance = 0
    chunk = 1
    add = n / 2
    while q + chunk < p:
        q += chunk
        chunk *= 2
        chance += add
        add /= 2
    return always, chance

rl = lambda: raw_input().strip()
cases = int(rl())
for cc in xrange(cases):
    lgn, p = map(int, rl().split())
    always, chance = solve(lgn, p)
    print 'Case #%d: %d %d' % (cc+1, always, chance)
