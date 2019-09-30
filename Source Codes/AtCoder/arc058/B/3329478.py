ai = lambda: list(map(int,input().split()))

mod = 10**9+7


def nCb(n, b):
    if b > n - b:
        b = n - b
    r = 1
    for k in range(n, n-b, -1):
        r = r * k % mod
    d = 1
    for k in range(1, b+1):
        d = d * k % mod
    return r * inv(d) % mod


def inv(x):
    return pow(x, mod - 2, mod)


h,w,a,b = ai()
aa = h-a-1
bb = w-b-1
c1 = nCb(aa+b, b)
c2 = nCb(a+bb-1, bb)
ans = c1 * c2
ans %= mod

for i in range(1, bb+1):
    c1 = c1 * (aa + b + i) * inv(b + i) % mod
    c2 = c2 * (bb - i + 1) * inv(a + bb - i) % mod
    ans += c1 * c2
    ans %= mod
print(ans)