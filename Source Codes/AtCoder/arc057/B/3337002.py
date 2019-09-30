# https://beta.atcoder.jp/contests/arc057/submissions/2075056

N, K = map(int, input().split())
*A, = [int(input()) for i in range(N)]

if sum(A) == K:
    print(1)
    exit(0)

INF = 10**18
C = [INF]*(N+1)
C[0] = 0
s = 0
for i in range(N):
    a = A[i]
    for j in range(N-1, -1, -1):
        if C[j] == INF:
            continue
        W = (a*C[j]//s + 1) if s else 1
        if W <= a:
            C[j+1] = min(C[j+1], C[j] + W)
    s += a
print(sum(e <= K for e in C)-1)