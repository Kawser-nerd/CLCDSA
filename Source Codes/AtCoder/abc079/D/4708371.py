from scipy.sparse.csgraph import floyd_warshall as wf

H, W = map(int, input().split())
C = [[int(i) for i in input().split()] for i in range(10)]
A = [[int(i) for i in input().split()] for i in range(H)]

B = wf(C)

ans = 0
for i in range(H):
    for j in range(W):
        if A[i][j] == -1:
            continue
        ans += B[A[i][j]][1]
        
print(int(ans))