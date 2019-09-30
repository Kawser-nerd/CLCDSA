import sys
inp = sys.stdin
T = int(inp.readline())

memo = dict()
def owp(ind):
  if ind in memo:
    return memo[ind]
  sum = 0.0
  length = 0
  for i in xrange(N):
    if mat[ind][i] != '.':
      sum += average(i, ind)
      length += 1
  memo[ind] = sum / length
  return sum / length

def average(ind, exc= -1):
  sum = 0.0
  length = 0
  for i in xrange(N):
    if i != exc and mat[ind][i] != '.':
      sum += int(mat[ind][i])
      length += 1
  return sum / length

for cas in xrange(1, T + 1):
  N = int(inp.readline())
  memo = dict()
  mat = []
  for i in xrange(N):
    mat.append(inp.readline().strip())
  print "Case #%d:" % cas
  for i in xrange(N):
    ans = average(i) * 0.25 + 0.5 * owp(i)
    oowp = 0
    length = 0
    for j in xrange(N):
      if mat[j][i] != '.':
        oowp += owp(j)
        length += 1
    oowp /= length
    ans += oowp * 0.25
    print ans
