def readint(): return int(raw_input())
def readlist(f): return map(f, raw_input().split())

def solve():
  N = readint()
  M = readlist(int)

  res1 = 0
  for i in range(1, N):
    if M[i] < M[i-1]:
      res1 += M[i-1] - M[i]

  v = 0
  for i in range(1, N):
    if M[i] < M[i-1]:
      v = max(v, M[i-1] - M[i])
  res2 = 0
  for i in range(N-1):
    res2 += min(v, M[i])

  return '{} {}'.format(res1, res2)

T = readint()
for t in range(T):
  print 'Case #{}: {}'.format(t+1, solve())
