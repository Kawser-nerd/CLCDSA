from math import pi

tnum = int(raw_input())

for ti in range(tnum):
    n, k = [int(x) for x in raw_input().split()]
    ps = [tuple([int(x) for x in raw_input().split()]) for _ in range(n)]
    ps = sorted(ps, key=lambda x: x[0])
    ans = 0
    for i in range(k-1, n):
        cur = sum(2*r*h for r, h in list(reversed(sorted(ps[:i], key=lambda x: x[0]*x[1])))[:k-1])
        cur += 2*ps[i][0]*ps[i][1]
        cur += ps[i][0]**2
        ans = max(ans, cur)
    print 'Case #{}: {:.9f}'.format(ti+1, ans*pi)
