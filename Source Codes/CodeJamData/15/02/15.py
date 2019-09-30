MAXP = 1001

def solve(P):
  best = MAXP
  for level in range(1,MAXP):
    moves = 0
    for p in P:
      moves += (p-1)/level
    if moves + level < best:
      best = moves + level
  return best

T = input()

for t in range(1,T+1):
  D = input()
  P = map(int,raw_input().split(' '))
  s = solve(P)
  print "Case #%d: %d" % (t,s)
