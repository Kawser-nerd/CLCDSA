inf = 10000

def solve(n, l, a, b):
    b.sort()

    ans = inf
    for i in xrange(n):
        c = []
        diff = a[0] ^ b[i]
        for j in xrange(n):
            c.append(a[j] ^ diff)
        c.sort()
        if b == c: ans = min(ans, bin(diff).count('1'))
    if ans == inf:
        print 'NOT POSSIBLE'
    else:
        print ans
    return

T = input()
for i in xrange(T):
    print 'Case #%d:' % (i + 1),
    [n, l] = map(int, raw_input().split())
    a = map(lambda x: int(x, 2), raw_input().split())
    b = map(lambda x: int(x, 2), raw_input().split())
    solve(n, l, a, b)
