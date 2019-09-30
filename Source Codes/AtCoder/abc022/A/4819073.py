ans = 0
n,s,t=map(int,input().split())
w = int(input())
for i in range(n - 1):
  if s <= w <= t:
    ans += 1
  w += int(input())
if s <= w <= t:
  ans += 1
print(ans)