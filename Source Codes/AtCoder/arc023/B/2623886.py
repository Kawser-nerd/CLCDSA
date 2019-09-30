h,w,d = [int(i) for i in input().split()]
a = 0
for hi in range(h):
  t = [int(i) for i in input().split()]
  for wi in range(w):
    l = hi + wi
    if l<=d and l%2==d%2:
      a=max(a,t[wi])
print(a)