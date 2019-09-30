a,b,c,d = map(int, input().split())
s = max(a,c)
f = min(b,d)
if s < f:
  print(f - s)
else:
  print(0)