H, W, A, B = map(int, input().split())
mod = 7 + 10**9

def Power(i, n):
    if n == 1:
        return i
    else:
        if n%2 == 0:
            return Power((i*i)%mod, n//2)
        else:
            return (Power((i*i)%mod, n//2) * i) % mod

NF = [1 for i in range(H+W+1)]
for i in range(2, H+W+1):
    NF[i] = (NF[i-1] * i) % mod

NFI = [1 for i in range(H+W+1)]
NFI[H+W] = Power(NF[-1], mod-2)
for i in reversed(range(1, H+W)):
    NFI[i] = (NFI[i+1] * (i+1)) % mod

Ans = 0
for w in range(B, W):
    upper = (NF[H-A+w-1] * NFI[w] * NFI[H-A-1]) % mod
    lower = (NF[W+A-w-2] * NFI[A-1] * NFI[W-w-1]) % mod
    Ans += upper * lower % mod
    Ans %= mod
print(Ans)