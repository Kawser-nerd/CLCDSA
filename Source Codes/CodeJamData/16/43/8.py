from collections import defaultdict

def get_lover(P, i):
  idx = P.index(i)
  if idx%2 == 0: return P[idx+1]
  return P[idx-1]

# p == 0, 1, 2, 3 -> North, East, South, West
def to_start(R, C, k):
  if k <= C: return (0, k, 2)
  if k <= R + C: return (k - C, C + 1, 3)
  if k <= R + 2*C: return (R + 1, C - (k - (R + C)) + 1, 0)
  return (R - (k - (R + 2*C)) + 1, 0, 1)

def is_start(R, C, (i, j, p)):
  if i == 0:
    assert p == 2
    return j
  elif j == C + 1:
    assert p == 3
    return C + i
  elif i == R + 1:
    assert p == 0
    return R + C + (C + 1 - j)
  elif j == 0:
    assert p == 1
    return R + 2*C + (R + 1 - i)
  return None

ADJ = (
  (3, 1), # North
  (2, 0), # East
  (1, 3), # South
  (0, 2)  # West
)
DIR = (
  (-1, 0, 2), # North
  (0, 1, 3), # East
  (1, 0, 0), # South
  (0, -1, 1)  # West
)
# B[i][j] == 0 if /
# B[i][j] == 1 if \
def neighbours(R, C, B, (i, j, p)):
  if i == 0:
    assert p == 2
    return [(i+1, j, 0)]
  elif i == R+1:
    assert p == 0
    return [(i-1, j, 2)]
  elif j == 0:
    assert p == 1
    return [(i, j+1, 3)]
  elif j == C+1:
    assert p == 3
    return [(i, j-1, 1)]
  res = [(i, j, ADJ[p][B[i-1][j-1]])]
  ni, nj, np = i + DIR[p][0], j + DIR[p][1], DIR[p][2]
  res.append((ni, nj, np))
  return res

def check(R, C, B, P):
  for k in range(1, 2*(R+C)+1):
    lover = get_lover(P, k)
    seen = defaultdict(bool)
    pos = to_start(R, C, k)
    seen[pos] = True
    Q = [pos]
    while len(Q) > 0:
      pos = Q.pop()
      for next_pos in neighbours(R, C, B, pos):
        if seen[next_pos]: continue
        tmp = is_start(R, C, next_pos)
        if tmp != None and tmp != lover: return False
        seen[next_pos] = True
        Q.append(next_pos)
  return True

_T = int(raw_input())
for _t in range(1, _T+1):
  
  R, C = map(int, raw_input().split())
  P = map(int, raw_input().split())
 
  res = ['IMPOSSIBLE']
  for Bcode in range(1 << R*C):
    cur = Bcode
    B = [[0]*C for _ in range(R)]
    for i in range(R):
      for j in range(C):
        B[i][j] = cur%2
        cur /= 2
    if check(R, C, B, P):
      res = []
      for i in range(R):
        res.append('')
        for j in range(C):
          res[-1] += '/' if B[i][j] == 0 else '\\'
      break

  print 'Case #{}:'.format(_t)
  for l in res: print l
