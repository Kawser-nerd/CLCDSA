n = int(input())
nl = {}
for _ in range(n-1):
  a, b = map(int, input().split())
  if a-1 in nl:
    nl[a-1].append(b-1)
  else:
    nl[a-1] = [b-1]
  if b-1 in nl:
    nl[b-1].append(a-1)
  else:
    nl[b-1] = [a-1]

fenl = [-1 for _ in range(n)]
sunl = [-1 for _ in range(n)]
fenl[0] = 1
sunl[-1] = 1
now = [0]
while now:
  tmp = []
  for _n in now:
    for nxt in nl[_n]:
      if fenl[nxt] == -1:
        tmp.append(nxt)
        fenl[nxt] = fenl[_n] + 1
  now = tmp

now = [n-1]
while now:
  tmp = []
  for _n in now:
    for nxt in nl[_n]:
      if sunl[nxt] == -1:
        tmp.append(nxt)
        sunl[nxt] = sunl[_n] + 1
  now = tmp

fm, sm = 0, 0
for i in range(n):
  if fenl[i] <= sunl[i]:
    fm += 1
  else:
    sm += 1

if fm <= sm:
  print('Snuke')
else:
  print('Fennec')