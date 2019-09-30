def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):
  D = readint()
  P = readarray(int)

  T = [0]*1001
  for p in P:
    T[p] += 1

  res = 1000000000
  for i in range(1, 1001):
    cur = i
    for p in P:
      cur += (p-1)/i
    res = min(res, cur)

  print 'Case #%i:'%(_t+1), res
