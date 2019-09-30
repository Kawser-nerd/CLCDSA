N = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(N):
  for j in range(N):
    ans = max(A[j]-A[i], ans)
print(ans)