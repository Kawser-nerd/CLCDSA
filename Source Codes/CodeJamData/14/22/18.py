import itertools

from collections import defaultdict
from random import randint

def getzip(zipcode, lst):
  res = ''
  for elm in lst:
    res += zipcode[elm]
  return res

def ok(lst, mp):
  n = len(lst)
  stack = []
  vis = [0] * n
 
  cur = lst[0]
  vis[cur] = 1
  stack.append(cur)
  
  for i in xrange(1, n):
    nxt = lst[i]
    while stack:
      now = stack[-1]
      if (now, nxt) in mp: break
      stack.pop()
    if not stack:
      return False
    stack.append(nxt)
  
  return True

def solve(tcase):
  n, m = (int(e) for e in raw_input('').split())
  zipcode = [raw_input('') for i in xrange(n)]
  road = [raw_input('').split() for i in xrange(m)]
  mp = defaultdict(int)
  for r in road:
    key = (int(r[0]) - 1, int(r[1]) - 1)
    mp[key] = 1
    key = (int(r[1]) - 1, int(r[0]) - 1)
    mp[key] = 1
  opt = range(n)
  res = 'z' * 100
  for elm in itertools.permutations(opt):
    if ok(elm, mp):
      res = min(res, getzip(zipcode, elm))
  print 'Case #%d: %s' % (tcase, res)

T = int(raw_input(''))
for tcase in xrange(1, T + 1):
  solve(tcase)