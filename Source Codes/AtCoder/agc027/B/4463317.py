N, X = map(int, input().split())
*xs, = map(int, input().split())

S = [0]*(N+1)
r = 0
for i in range(N):
    S[i+1] = r = xs[i] + r

ans = 10**30
for k in range(1, N+1):
    r = (S[N] - S[N - k]) * 5
    for i in range(1, (N-1)//k):
        r += (S[N - k*i] - S[N - k*(i+1)]) * (2*i + 3)
    p = (N-1)//k
    r += (S[N - k*p]) * (2*p + 3)
    ans = min(ans, r + (k + N)*X)
print(ans)