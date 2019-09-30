N, A, B = map(int, input().split())
a = sorted([[0, n] for n in (map(int, input().split()))])
mod = 10**9+7
_d = 1

if A > 1:
    while B and a[0][1]*A**(a[0][0]+1) < a[-1][1]*A**(a[-1][0]):
        d, m = a[0][1]*A // mod, a[0][1]*A % mod
        a[0][0] += d
        a[0][1] = m
        a.sort()
        B -= 1

    _d, B = B // N, B % N

    while B:
        d, m = a[0][1]*A // mod, a[0][1]*A % mod
        a[0][0] += d
        a[0][1] = m
        a.sort()
        B -= 1

for _, ans in a:
    print((ans * pow(A, _d, mod)) % mod)