N = int(input())
H = [int(input()) for i in range(N)]

L = [1] * N
R = [1] * N

for i in range(1, N):
    L[i] = L[i-1] * (H[i-1] < H[i]) + 1
for i in range(N-2, -1, -1):
    R[i] = R[i+1] * (H[i+1] < H[i]) + 1

ans = 0
for i in range(N):
    ans = max(ans, L[i] + R[i])
print(ans - 1)