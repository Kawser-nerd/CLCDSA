H, W, D = map(int, input().split())
A = [[int(i) for i in input().split()] for i in range(H)]

L = [[] for i in range(H * W + 1)]
for i in range(H):
    for j in range(W):
        L[A[i][j]] = [i + 1, j + 1]
        
d = [0] * (H * W + 1)
for i in range(D + 1, H * W + 1):
    d[i] = d[i - D] + abs(L[i][0] - L[i - D][0]) + abs(L[i][1] - L[i - D][1])

Q = int(input())
for i in range(Q):
    l, r = map(int, input().split())
    print(d[r] - d[l])