#!/usr/bin/python

rl = raw_input

def make(s):
  while s[0] == ' ':
    s = s[1:]
  if s[0] != '(': raise Exception
  s = s[1:]
  while s[0] == ' ':
    s = s[1:]
  i = 0
  while s[i] != ' ' and s[i] != ')':
    i += 1
  x = float(s[0:i])
  s = s[i:]
  while s[0] == ' ':
    s = s[1:]
  if s[0] == ')':
    return ((x,),s[1:])
  i = 0
  while "a" <= s[i] <= "z":
    i += 1
  f = s[0:i]
  t1, s = make(s[i:])
  t2, s = make(s)
  while s[0] == ' ':
    s = s[1:]
  if s[0] != ')': raise Exception
  return ((x,f,t1,t2),s[1:])

def solve(a, tree, p):
  p *= tree[0]
  if len(tree) == 1:
    return p
  if tree[1] in a:
    return solve(a, tree[2], p)
  return solve(a, tree[3], p)

N = int(rl())
for cas in xrange(1,N+1):
  L = int(rl())
  tree = make(" ".join(rl() for i in xrange(L)))[0]
  A = int(rl())
  print "Case #%d:" % cas
  for i in xrange(A):
    a = rl().split()[2:]
    print "%.6lf" % solve(a, tree, 1.0)


