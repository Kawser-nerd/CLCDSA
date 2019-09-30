n,s,t = map(int,input().split())
w = int(input())
a = [int(input()) for i in range(n-1)]
ans = 0
if s <= w <= t:
  ans += 1

for i in range(n-1):
  w += a[i]
  if s <= w <= t:
    ans += 1

print(ans)