def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):

  N, S = raw_input().split()
  N = int(N)

  res = 0
  cur = 0
  for i in range(N+1):
    if i > cur:
      res += i - cur
      cur = i
    cur += int(S[i])

  print 'Case #%i:'%(_t+1), res
