H, W, A, B = map(int, input().split())
MOD = 10**9 + 7
c1 = []
c2 = []
for i in range(H-A):
    if i == 0:
        c1.append(1)
        c2.append(1)
    else:
        m = pow(i, MOD-2, MOD)
        t1 = (c1[i-1]*(B-1+i) % MOD) * m
        c1.append(t1 % MOD)
        t2 = (c2[i-1]*(W-B-1+i) % MOD) * m
        c2.append(t2 % MOD)
for i in range(H-A, H):
    t = (c2[i-1]*(W-B-1+i) % MOD) * pow(i, MOD-2, MOD)
    c2.append(t % MOD)
ans = 0
for i in range(len(c1)):
    ans += (c1[i]*c2[-i-1]) % MOD
print(ans % MOD)