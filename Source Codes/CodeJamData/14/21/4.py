from sys import stdin

def transform(s):
  ret = []
  for c in s:
    if len(ret) == 0 or ret[-1][0] != c:
      ret.append([c, 0])
    else:
      ret[-1][1] = ret[-1][1] + 1
  return ret

def take_first(t):
  return [x[0] for x in t]

def cost(l):
  l.sort()
  return sum(abs(x - l[len(l)/2]) for x in l)

def solve(ss):
  tmp = map(transform, ss)
  for t in tmp:
    if take_first(t) != take_first(tmp[0]):
      return 'Fegla Won'

  ret = 0
  for i in range(len(tmp[0])):
    ret += cost([t[i][1] for t in tmp])
  return ret

T = int(stdin.readline())

for no in range(1, T+1):
  N = int(stdin.readline())
  ss = []
  for i in range(N):
    ss.append(stdin.readline().strip())
  print "Case #{}: {}".format(no, solve(ss))
