r = raw_input

def solve():
  N = int(r())
  P = map(int, r().split())
#  print 'solving', N, P
  names = map(lambda x: chr(ord('A') + x), range(N))
  ans = []
  while True:
    mx = max(P)
    if mx == 0:
      break
    cands = filter(lambda i: P[i] == mx, range(N))
    if len(cands) == 2:
      ans.append(names[cands[0]] + names[cands[1]])
      P[cands[0]] -= 1
      P[cands[1]] -= 1
    else:
      ans.append(names[cands[0]])
      P[cands[0]] -= 1
  return ' '.join(ans)

T = int(r())
for t in range(1, T + 1):
  print 'Case #%d: %s' % (t, solve())
