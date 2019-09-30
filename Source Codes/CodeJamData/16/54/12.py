_T = int(raw_input())
for _t in range(1, _T+1):

  N, L = map(int, raw_input().split())
  G = raw_input().split()
  B = raw_input()

  if B in G:
    res = 'IMPOSSIBLE'
  else:
    if L == 1:
      res1 = '?'
      res2 = '0'
    else:
      res1 = '?' * (L-1)
      res2 = '10' * (L-1) + '?1'
    
    res = ' '.join((res1, res2))

  print 'Case #{}: {}'.format(_t, res)
