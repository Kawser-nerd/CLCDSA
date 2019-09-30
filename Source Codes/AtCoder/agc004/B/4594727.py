import numpy as np
N, x = map(int, input().split())
A = list(map(int, input().split()))
A += A
A = np.array(A, int)
INF = 10 ** 18
ans = INF
B = np.ones(N, int) * INF
for cnt in range(N):
    np.minimum(A[N-cnt:2*N-cnt], B, B)
    ans = min(ans, cnt * x + np.sum(B))

print(ans)