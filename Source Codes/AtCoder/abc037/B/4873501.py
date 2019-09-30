n, q = map(int, input().split())

a = [0] * n

for i in range(q):
  l, r, t = map(int, input().split())
  a = [t if (l-1)<=x<=(r-1) else y for x, y in enumerate(a)]

print(*a, sep="\n")