#!/usr/bin/env python3

import sys

t_n = int(sys.stdin.readline())

def gcd( a, b ):
    return a if b == 0 else gcd(b, a % b)

class F:
    def __init__( self, a, b ):
        d = gcd(a, b)
        a //= d
        b //= d
        self.a, self.b = a, b
    def __add__( self, pair ):
        return F(self.a * pair.b + pair.a * self.b, self.b * pair.b)
    def __mul__( self, pair ):
        return F(self.a * pair.a, self.b * pair.b)
    def __lt__( self, pair ):
        return self.a * pair.b < self.b * pair.a;

for t_t in range(1, t_n+1):
    n = int(sys.stdin.readline())
    cars = []
    for i in range(n):
        a, b, c = sys.stdin.readline().split()
        cars.append((a, int(b), int(c)))
    times = [F(0,1)]
    def add_time( a, b ):
        # print("add time (a=%d, b=%d)" % (a, b), file=sys.stderr)
        if (a > 0):
            times.append(F(a, b))
    for i in range(n):
        for j in range(n):
            if cars[i][1] <= cars[j][1]: continue
            for d in [-5, 0, 5]:
                add_time(cars[j][2] - cars[i][2] + d, cars[i][1] - cars[j][1])
    t_r = []
    for x in sorted(times):
        if not t_r or t_r[-1] < x:
            t_r.append(x)
    times = t_r
    # for t in times:
    #     print("t=%.2f (%d/%d)" % (t.a / t.b, t.a, t.b), file=sys.stderr)
    k = len(times)
    m = 2 + 2 * n * k
    # print("m = %d (n=%d, k=%d)" % (m, n, k))
    time = [F(0, 1) for i in range(m)]
    for i, t in enumerate(times):
        for j in range(n):
            time[2 + i * 2 * n + j * 2] = t
            time[2 + i * 2 * n + j * 2 + 1] = t
    # for i, t in enumerate(time):
    #     print("time[i=%d] = %.2f (%d/%d)" % (i, t.a / t.b, t.a, t.b))
    g = [[] for i in range(m)]
    def edge( a, b ):
        # print("edge (%d, %d)" % (a, b))
        g[a].append(b)
        g[b].append(a)
    for i in range(n):
        for j, t in enumerate(times):
            c_a = 2 + j * 2 * n + i * 2
            c_b = 2 + j * 2 * n + i * 2 + 1
            edge(c_a, c_b)
            change = True
            for ii in range(n):
                if i == ii: continue
                pos_1 = t * F(cars[i][1], 1) + F(cars[i][2], 1)
                pos_2 = t * F(cars[ii][1], 1) + F(cars[ii][2], 1)
                if pos_1 < pos_2 + F(5, 1) and pos_2 < pos_1 + F(5, 1):
                    change = False
                    t_a = 2 + j * 2 * n + ii * 2
                    t_b = 2 + j * 2 * n + ii * 2 + 1
                    edge(c_a, t_a)
                    edge(c_b, t_b)
            if not change:
                p_a = 2 + (j - 1) * 2 * n + i * 2
                p_b = 2 + (j - 1) * 2 * n + i * 2 + 1
                if j == 0:
                    p_a = 1 if cars[i][0] == 'L' else 0
                    p_b = 1 if cars[i][0] == 'R' else 0
                edge(p_a, c_b)
                edge(p_b, c_a)
    ans = F(0, 1)
    ok = True
    for k in range(2, m+1):
        if k != m and not time[k - 1] < time[k]: continue
        c = [None for x in range(k)]
        global good
        good = True
        def dfs( u, color ):
            global good
            if c[u] is not None and c[u] != color:
                # print("dfs(u=%d, color=%d)" % (u, color))
                good = False
                return
            if c[u] is not None: return
            c[u] = color
            for x in g[u]:
                if x >= k: continue
                dfs(x, 1-color)
        dfs(0, 0)
        dfs(1, 1)
        for i in range(k):
            if c[i] is not None: continue
            dfs(i, 0)
        if good:
            ans = time[k - 1]
        else:
            ok = False
            break
    if ok:
        print("Case #%d: Possible" % t_t)
    else:
        print("Case #%d: %.10f" % (t_t, ans.a / ans.b))

