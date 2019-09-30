N, K = map(int, input().split())
A = [int(input()) for i in range(N)]

cur = 0; ans = 0
val = 10**9
for i in range(N):
    if val < A[i]:
        cur += 1
    else:
        cur = 1
    if cur >= K:
        ans += 1
    val = A[i]
print(ans)