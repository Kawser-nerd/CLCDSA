N = int(input())
L = list(map(int, input().split()))
ans = 0
L.sort()
for i in range(N):
  ans += L[2*i]
print(ans)