H, W = list(map(int, input().split()))
N = int(input())
A = []
a = list(map(int, input().split()))
for i in range(N):
    A += [i + 1] * a[i]

L = [[0 for i in range(W)] for j in range(H)]
for i in range(H * W):
    if int((i // W)) % 2 == 0:
        L[int((i // W))][i % W] = A[i]
    else:
        L[int((i // W))][-1 - i % W] = A[i]

for i in range(H):
    L[i] = list(map(str, L[i]))


for i in range(H):
    print(" ".join(L[i]))