n, m = map(int, input().split())

qd = {}
for _ in range(m):
  a, b = map(int, input().split())
  if a not in qd:
    qd[a] = 1
  else:
    qd[a] += 1
  if b not in qd:
    qd[b] = 1
  else:
    qd[b] += 1

if all(v % 2 == 0 for v in qd.values()):
  print('YES')
else:
  print('NO')