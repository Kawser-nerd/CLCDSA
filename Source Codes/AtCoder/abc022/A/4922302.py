n, s, t = map(int, input().split())
w = int(input())
ans = 0
if w>=s and w<=t:
  ans += 1
for i in range(n-1):
  a = int(input())
  w += a
  if w>=s and w<=t:
    ans += 1
print(ans)