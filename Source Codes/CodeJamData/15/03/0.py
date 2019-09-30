def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

# 1 -- 1
# 2 -- i
# 3 -- j
# 4 -- k
def to_quat(c):
  if c == 'i': return 2
  if c == 'j': return 3
  if c == 'k': return 4
def mult(a, b):
  if a < 0:
    return -mult(-a, b)
  if b < 0:
    return -mult(a, -b)
  if a == 1: return b
  if b == 1: return a
  if a == b: return -1
  if a == 2 and b == 3: return 4
  if a == 2 and b == 4: return -3
  if a == 3 and b == 2: return -4
  if a == 3 and b == 4: return 2
  if a == 4 and b == 2: return 3
  if a == 4 and b == 3: return -2
  raise RuntimeError

_T = readint()
for _t in range(_T):

  L, X = readarray(int)
  S = raw_input()

  A = [1]
  for s in S:
    A.append(mult(A[-1], to_quat(s)))
  B = [1]
  for s in reversed(S):
    B.append(mult(to_quat(s), B[-1]))
  B.reverse()

  P = [1]
  for i in range(3):
    P.append(mult(P[-1], A[L]))
  
  if P[X%4] != -1:
    res = 'NO'
  else:
    found = True
    for pi in range(4):
      for li in range(L+1):
        if mult(P[pi], A[li]) == 2: break
      else: continue
      break
    else: found = False
    
    if not found:
      res = 'NO'
    else:
      for pj in range(4):
        for lj in range(L, -1, -1):
          if mult(B[lj], P[pj]) == 4: break
        else: continue
        break
      else: found = False

      if not found:
        res = 'NO'
      else:
        if pi*L + li + pj*L + (L - lj) <= L*X:
          res = 'YES'
        else:
          res = 'NO'
  print 'Case #%i:'%(_t+1), res
