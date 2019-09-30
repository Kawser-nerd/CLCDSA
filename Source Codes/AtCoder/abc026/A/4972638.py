a = int(input())
ans = 0
for i in range(int(a/2)):
  x = i + 1
  m = x * (a - x)
  if ans < m:
    ans = m

print(ans)