from collections import defaultdict

_T = int(raw_input())
for _t in range(1, _T+1):

  N = int(raw_input())
  d = defaultdict(int)
  for i in range(2*N-1):
    for h in map(int, raw_input().split()):
      d[h] += 1
  
  res = []
  for h in d:
    if d[h]%2 == 1: res.append(h)

  res.sort()
  res = ' '.join(map(str, res))

  print 'Case #{}: {}'.format(_t, res)
