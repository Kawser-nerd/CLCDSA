def invalid(n, r, p, s):
  N = 1 << n
  if max(r, p, s) > (N+2)/3: return True
  if min(r, p, s) < N/3: return True
  return False

def build(n, r, p, s):
  assert not invalid(n, r, p, s)
  if n == 1:
    if p > 0 and r > 0: return 'PR'
    if p > 0 and s > 0: return 'PS'
    return 'RS'

  if p == r > s:
    pl, rl, sl = (p+1)/2, r/2, s/2
  elif p == s > r:
    pl, rl, sl = (p+1)/2, r/2, s/2
  elif p > r == s:
    pl, rl, sl = p/2, (r+1)/2, s/2
  elif r == s > p:
    pl, rl, sl = p/2, (r+1)/2, s/2
  elif r > s == p:
    pl, rl, sl = (p+1)/2, r/2, s/2
  elif s > r == p:
    pl, rl, sl = (p+1)/2, r/2, s/2
  else:
    assert False
  return build(n-1, rl, pl, sl) + build(n-1, r-rl, p-pl, s-sl)

_T = int(raw_input())
for _t in range(1, _T+1):

  n, R, P, S = map(int, raw_input().split())
  
  if invalid(n, R, P, S):
    res = 'IMPOSSIBLE'
  else:
    res = build(n, R, P, S)
  

  print 'Case #{}: {}'.format(_t, res)
