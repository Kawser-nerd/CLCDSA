from functools import *

inf = open('A-large.in')
ouf = open('output.txt', 'w')
input = lambda: inf.readline().strip()
print = partial(print, file = ouf)


def solve():
    r, t = map(int, input().split())
    le = 1
    ri = 10 ** 18
    while le + 1 < ri:
        m = (le + ri) // 2
        if (2 * r + 1) * m + 2 * (m - 1) * m <= t:
            le = m
        else:
            ri = m
    print(le)
    
    
tests = int(input())
for z in range(tests):
    print("Case #{}: ".format(z + 1), end = '')
    solve()

ouf.close()