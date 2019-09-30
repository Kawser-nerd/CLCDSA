N = int(input())
A = [int(input()) for _ in range(N)]

ans = 1e9
for i in range(1 << N):
  a, b = 0, 0
  for j in range(N):
    if ((i >> j) & 1) == 1:
      a += A[j]
    else:
      b += A[j]
  ans = min(ans, max(a, b))
print(ans)