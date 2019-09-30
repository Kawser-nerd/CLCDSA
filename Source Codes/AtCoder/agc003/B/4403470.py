n = int(input())
a = [int(input()) for i in range(n)]
ans = 0
for i in range(n-1):
  if a[i]>=2:
    ans += a[i]//2
    a[i] = a[i]%2
  if a[i]==1:
    if a[i+1]>=1:
      ans += 1
      a[i] -= 1
      a[i+1] -=1
ans = ans +a[n-1]//2
print(ans)