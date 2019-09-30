Q = 998244353
def getInv(N):
    inv = [0] * (N + 1)
    inv[0] = 1
    inv[1] = 1
    for i in range(2, N + 1):
        inv[i] = (-(Q // i) * inv[Q%i]) % Q
    return inv

N, A, B, K = map( int, input().split())
ans = 0
invs = getInv(N)
nCk = [1]*(N+1)
for i in range(1,N+1):
    nCk[i] = (nCk[i-1]*(N-i+1)*invs[i])%Q
for i in range(N+1):
    j = (K-A*i)//B
    if A*i + B*j == K and j <= N and 0 <= j:
        j = (K-A*i)//B
        ans = (ans + nCk[i]*nCk[j])%Q
print(ans)