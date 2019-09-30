n, m = map(int, input().split())
l = list(range(n+1))
for _ in range(m):
  a = l.index(int(input()))
  l[0],l[a] = l[a],l[0]
l.pop(0)
for i in l:
  print(i)