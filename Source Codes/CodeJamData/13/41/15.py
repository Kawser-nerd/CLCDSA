from sys import stdin
from collections import defaultdict
def pay(x):
    return x * (x + 1) / 2
def solve():
    read_ints = lambda: map(int, stdin.readline().split())
    n, m = read_ints()
    q = defaultdict(int)
    mod = 1000002013
    d1 = d2 = 0
    for _ in xrange(m):
        a, b, p = read_ints()
        q[a] += p
        q[b] -= p
        d1 += p * pay(b - a) % mod
        d1 %= mod
    st = []
    for x in sorted(q.keys()):
        if q[x] > 0:
            st.append([x, q[x]])
        else:
            c = -q[x]
            while c > 0:
                a, b = st[-1]
                t = min(b, c)
                d2 += t * pay(x - a) % mod
                d2 %= mod
                c -= t
                if t >= b:
                    st.pop()
                else:
                    st[-1][1] -= t
    return (d2 - d1 + mod) % mod
T = int(stdin.readline())
for i in xrange(0, T):
    print "Case #%d: %d" % (i+1, solve())
