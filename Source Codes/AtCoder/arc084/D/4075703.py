N, X = input().split()
N = int(N); X = int(X, 2)
p = int(input(), 2)
for i in range(N-1):
    v = int(input(), 2)
    if p > v:
        p, v = v, p
    while 0 < p:
        q = (v ^ (p << (v.bit_length() - p.bit_length())))
        if p < q:
            p, v = p, q
        else:
            p, v = q, p
    p = v

lx = X.bit_length()
lp = p.bit_length()

MOD = 998244353
ans = (X >> (p.bit_length() - 1)) % MOD

q = p << (lx - lp)
b = 1 << (lx - 1)

x = 0; y = 0
for k in range(lx - lp, -1, -1):
    if b & (X ^ y):
        y ^= q
    b >>= 1; q >>= 1
if y <= X:
    ans = (ans + 1) % MOD
print(ans)