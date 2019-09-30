m, d = map(int,input().split())
res = 0
if m <= d:
  res = m
else:
  res = m-1
print(res)