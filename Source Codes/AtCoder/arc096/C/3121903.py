N, M = map(int, input().split())
fact = [1]*(N+1)
rfact = [1]*(N+1)
for i in range(1, N+1):
    fact[i] = r = (i * fact[i-1]) % M
    rfact[i] = pow(r, M-2, M)

S = [1]

rev2 = pow(2, M-2, M)
base = pow(2, N, M)
ans = 0
S = [1]
for K in range(N+1):
    res = (fact[N] * rfact[K] * rfact[N-K]) % M
    res = (res * pow(2, pow(2, N - K, M-1), M)) % M
    b = 1
    v = 0
    T = [0]*(K+2)
    for L in range(K):
        T[L+1] = s = (S[L] + (L+1)*S[L+1]) % M
        v += s * b
        b = (b * base) % M
    v += b
    T[K+1] = 1
    S = T
    res = (res * v) % M
    if K % 2:
        ans -= res
    else:
        ans += res
    ans %= M

    base = (base * rev2) % M
print(ans)