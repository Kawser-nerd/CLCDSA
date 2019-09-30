n,m = map(int, input().split())
d = dict()
for i in range(1,n+1):
  d[i] = 0
for _ in range(m):
  a = map(int, input().split())
  for x in a:
    d[x] += 1
    d[x] %= 2
if any(d.values()):
  print("NO")
else:
  print("YES")