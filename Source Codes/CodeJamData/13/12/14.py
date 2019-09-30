T = int(raw_input())

def dumb(ce, val, E, R, v):
  if len(v) == 1:
    return val + ce * v[0]
  mval = 0
  for i in range(ce+1):
    vv = dumb(min(E, ce - i + R), val + i*v[0], E, R, v[1:])
    if vv > mval:
      mval = vv
  return mval

for case in range(1,T+1):
  E, R, N = map(int, raw_input().split())
  v = map(int, raw_input().split())
  
  nxb = [-1 for i in range(N)]
  for i in range(N):
    for j in range(i+1,N):
      if v[j] > v[i]:
        nxb[i] = j
        break
  ce = E
  val = 0
  for i in range(N):
    nb = nxb[i]
    if nb == -1:
      val = val + v[i] * ce
      ce = min(E, R)
    else:
      rg = E - R * (nb - i)
      spe = max(0, min(ce, ce - rg))
      val = val + v[i] * spe
      ce = min(E, ce - spe + R)
  
  
  print 'Case #' + str(case) + ': ' + str(val)