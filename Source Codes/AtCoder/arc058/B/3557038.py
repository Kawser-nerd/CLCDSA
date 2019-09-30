def inpl(): return [int(i) for i in input().split()]

mod = 10**9+7
H, W, A, B = inpl()
fac = [1 for _ in range(H+W-1)]
for i in range(H+W-2):
    fac[i+1] = (i+1)*fac[i]%mod

inv = [1 for _ in range(H+W-1)]
for i in range(2,H+W-2):
    inv[i] = (-(mod//i) * inv[mod%i]) %mod    

facinv = [1 for _ in range(H+W-1)]
for i in range(H+W-2):
    facinv[i+1] = inv[i+1]*facinv[i]%mod


ans = 0
for i in range(W-B):
    ans += (fac[H+B-A-1+i] * fac[W+A-B-2-i] * facinv[H-A-1] * facinv[B+i]\
    * facinv[A-1] * facinv[W-B-1-i] )%mod
print(ans%mod)