import numpy

n, a, b = map(int, input().split())
v = list(map(int, input().split()))

v.sort()

res = numpy.average(v[n - a:])
x = min(v[n - a:])

nCr = {}
def cmb(n, r):
    if r == 0 or r == n: return 1
    if r == 1: return n
    if (n,r) in nCr: return nCr[(n,r)]
    nCr[(n,r)] = cmb(n-1,r) + cmb(n-1,r-1)
    return nCr[(n,r)]

if v[n - 1] != x:
    print(res)
    c = v[n-a:].count(x)
    m = v.count(x)
    print(cmb(m, c))
else:
    print(res)
    ans = 0
    m = v.count(x)
    for i in range(a, min(m, b) + 1):
        ans += cmb(m, i)
    print(ans)