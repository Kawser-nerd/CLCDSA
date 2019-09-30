N, M, A = None, None, None

def find(ch):
  res = []
  for i in range(N):
    for j in range(M):
      if A[i][j] in ch:
        res.append((i, j))
  return sorted(res)

def code(x):
  return hash(tuple(x))

di = (-1, +1, 0, 0)
dj = (0, 0, -1, +1)
dk = (1, 0, 3, 2)
def move(i, j, d):
  ii, jj = i+di[d], j+dj[d]
  if ii < 0 or jj < 0 or ii >= N or jj >= M:
    return None
  return ii, jj

def can_move(i, j, d, other):
  x = move(i, j, d)
  if x is None: return None
  ii, jj = x
  y = move(i, j, dk[d])
  if y is None: return None
  iii, jjj = y
  if A[ii][jj] != '.' or A[iii][jjj] != '.':
    return None
  if (ii, jj) == other or (iii, jjj) == other:
    return None
  return ii, jj

def stable(pos):
  if len(pos) < 2:
    return True
  i, j = pos[0]
  ii, jj = pos[1]
  for d in range(4):
    x = move(i, j, d)
    if x is None: continue
    if x == (ii, jj):
      return True
  return False

def main():
  global N, M, A
  T = int(raw_input())
  for t in range(1, T+1):
    print 'Case #%d:' % t,
    N, M = map(int, raw_input().split())
    A = []
    for i in range(N):
      A.append(list(raw_input()))
    start = find(('o', 'w'))
    end = find(('x', 'w'))
    assert len(start) == len(end)
    if len(start) > 2:
      print 'too big'
      continue
    for i in range(N):
      for j in range(M):
        if A[i][j] in ('o', 'w', 'x'):
          A[i][j] = '.'

    Q = [start]
    dist = {}
    dist[code(start)] = 0
    solved = False
    while len(Q) > 0:
      head = Q[0]
      Q = Q[1:]
      if head == end:
        print dist[code(end)]
        solved = True
        break
      is_stable = stable(head)

      for idx in range(len(head)):
        i, j = head[idx]
        other = head[1-idx] if len(head) >= 2 else None
        for d in range(4):
          next = can_move(i, j, d, other)
          if next is None: continue
          ii, jj = next
          if other:
            next = sorted([(ii, jj), other])
          else:
            next = [(ii, jj)]
          if not is_stable and not stable(next):
            continue
          if code(next) in dist:
            continue
          dist[code(next)] = dist[code(head)] + 1
          Q.append(next)

    if not solved:
      print -1


if __name__ == '__main__':
  main()
