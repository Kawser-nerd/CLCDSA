N = int(input())
H = [int(input()) for _ in range(N)]

U = [1]*N
S = [1]*N

for i in range(1, N):
    U[i] = (U[i-1]) * (H[i-1] < H[i]) + 1

for i in range(N-1)[::-1]:
    S[i] = (S[i+1]) * (H[i] > H[i+1]) + 1

ans = 0
for i in range(N):
    ans = max(ans, U[i]+S[i])
print(ans-1)