n = int(input())
d = {}
for i in range(n):
  s = str(input())
  if not s in d:
    d[s] = 1
  else:
    d[s] += 1
print(max(d, key=d.get))