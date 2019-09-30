N = int(input())
a = [int(i) for i in input().split()]
ans = 0
for i in range(N):
  ans += a[i]-1
print(ans)