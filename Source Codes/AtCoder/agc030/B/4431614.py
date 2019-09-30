L, N = map(int, input().split())
X = [int(input()) for i in range(N)]

Y = [0]*(N+1)
for i in range(N):
    Y[i+1] = X[i] + Y[i]

ans = max(X[N-1], L - X[0])
for i in range(N-1):
    P = i+1; Q = N - (i+1)
    if P < Q:
        ans = max(ans, 2*Y[i+1] + 2*(L*(P+1) - (Y[i+P+2] - Y[i+1])) - (L - X[i+1]))
    elif P > Q:
        ans = max(ans, 2*(Y[i+1] - Y[i-Q]) - X[i] + 2*(L*Q - (Y[N] - Y[i+1])))
    K = min(P, Q)
    ans = max(ans, 2*(Y[i+1] - Y[i+1-K]) + 2*(L*K - (Y[i+K+1] - Y[i+1])) - min(X[i], L-X[i+1]))
print(ans)