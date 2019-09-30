from functools import *

inf = open('A-large.in')
ouf = open('output.txt', 'w')
input = lambda: inf.readline().strip()
print = partial(print, file = ouf)

M = 1000002013

def dist(n, l, r):
    return (r - l) * n - (r - l - 1) * (r - l) // 2

def solve():
    n, m = map(int, input().split())
    o, e, p = [], [], []
    ev = []
    ans0 = 0
    for i in range(m):
        to, te, tp = map(int, input().split())
        to -= 1
        te -= 1
        o.append(to)
        e.append(te)
        p.append(tp)
        ev.append((1, to, tp))
        ev.append((-1, te, tp))
        ans0 += dist(n, to, te) * tp
    ev.sort(key = lambda t: (t[1], -t[0]))
    st = []
    ans1 = 0
    for t in ev:
        tt, ti, tp = t
        if tt == 1:
            st.append([ti, tp])
        else:
            while tp > 0:
                tpp = st[-1][1]
                td = min(tpp, tp)
                tp -= td
                st[-1][1] -= td
                ans1 += dist(n, st[-1][0], ti) * td
                if st[-1][1] == 0:
                    st.pop()
    print((ans0 - ans1) % M)
    
    
tests = int(input())
for z in range(tests):
    print("Case #{}: ".format(z + 1), end = '')
    solve()

ouf.close()