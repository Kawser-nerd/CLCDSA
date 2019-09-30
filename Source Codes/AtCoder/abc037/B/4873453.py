n, q = map(int, input().split())

a = [0] * n

for i in range(q):
  l, r, t = map(int, input().split())
  for x in range(l-1, r):
    a[x] = t

print(*a, sep="\n")