import itertools

def get(N, code, i, j):
  idx = i*N+j
  return (code >> idx)&1

def check_aux(N, code, order, busy, k):
  if k == N: return True
  ok = False
  for m in range(N):
    if get(N, code, order[k], m) == 0: continue
    if busy[m]: continue
    # Machine is free and the worker knows how to operate it
    busy[m] = True
    if not check_aux(N, code, order, busy, k+1): return False
    ok = True
    busy[m] = False
  return ok

def check(N, code):
  for order in itertools.permutations(range(N)):
    if not check_aux(N, code, order, [False]*N, 0): return False
  return True

DATA = [[]]

for N in range(1, 5):
  DATA.append([])
  for code in range(1 << (N**2)):
    DATA[-1].append(check(N, code))

_T = int(raw_input())
for _t in range(1, _T+1):

  N = int(raw_input())
  G = [map(int, raw_input()) for _ in range(N)]

  res = N**2

  for code in range(1 << (N ** 2)):
    if not DATA[N][code]: continue
    score = 0
    ok = True
    for k in range(N):
      for m in range(N):
        v = get(N, code, k, m)
        if G[k][m] > v:
          ok = False
          break
        score += v - G[k][m]
      if not ok: break
    if not ok: continue
    res = min(res, score)

  print 'Case #{}: {}'.format(_t, res)
