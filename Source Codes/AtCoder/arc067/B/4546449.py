n, a, b = map(int, input().split())
xlist = list(map(int, input().split()))

prevx = xlist[0]
c = 0
for x in xlist[1:]:
  if (x - prevx) * a > b:
    c += b
  else:
    c += (x - prevx) * a
  prevx = x
print(c)