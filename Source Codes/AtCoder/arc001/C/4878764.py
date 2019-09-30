import itertools
import sys

x = []
y = []
ix = [0, 1, 2, 3, 4, 5, 6, 7]
iy = [0, 1, 2, 3, 4, 5, 6, 7]
p1 = []
p2 = []
for i in range(8):
  r = input()
  t = r.find('Q')
  if t > -1:
    x.append(i)
    ix.remove(i)
    if t in y:
      print('No Answer')
      sys.exit()
    y.append(t)
    iy.remove(t)
    if (i+t) in p1 or (i-t) in p2:
      print('No Answer')
      sys.exit()
    p1.append(i+t)
    p2.append(i-t)
    if len(x) > 2:
      break
if len(x) < 3 or len(y) < 3:
  print('No Answer')
  sys.exit()

o1 = list(itertools.permutations(ix))
o2 = list(itertools.permutations(iy))

dat = list(itertools.product(o1, o2))
for i in dat:
  c1 = []
  c2 = []
  for s, t in zip(i[0], i[1]):
    if (s+t) in c1 or (s+t) in p1 or (s-t) in c2 or (s-t) in p2:
      break
    else:
      c1.append(s+t)
      c2.append(s-t)
  if len(c1) == 5:
    x.extend(list(i[0]))
    y.extend(list(i[1]))
    break

if len(x) < 8:
  print('No Answer')
  sys.exit()

for i in range(8):
  print('.'*y[x.index(i)] + 'Q' + '.'*(7-y[x.index(i)]))