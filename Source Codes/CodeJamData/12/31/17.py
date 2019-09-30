#!/usr/bin/env python
test = 'A-large'

input = open('%s.in'%test)
output = open('%s.out'%test, 'w')

# import sys
# output = sys.stdout

def solve(N, parents):
  ancestors = [None for i in parents]
  def calculate_ancestors(i):
    if ancestors[i] is not None:
      return ancestors[i]
    a = set([])
    for p in parents[i]:
      a.update(calculate_ancestors(p))
    a.update(parents[i])
    ancestors[i] = a
    return a
  for i in xrange(N):
    calculate_ancestors(i)
  for i in xrange(N):
    sum = 0
    for p in parents[i]:
      sum += len(ancestors[p]) + 1
    if sum != len(ancestors[i]):
      return True
  return False

T = int(input.readline())
for t in xrange(T):
  N = int(input.readline())
  parents = []
  for i in xrange(N):
    p = map(int, input.readline().split())
    p = map(lambda x: x-1, p[1:])
    parents.append(p)
  if solve(N, parents):
    print >>output, "Case #%s: Yes" % (t+1)
  else:
    print >>output, "Case #%s: No" % (t+1)


