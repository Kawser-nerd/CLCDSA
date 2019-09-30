import sys
inp = sys.stdin

T = int(inp.readline())
for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  s, n = inp.readline().split()
  n = int(n)
  L = len(s)
  ans = 0
  t = 0
  c = 0
  k = 0
  for i in xrange(L):
    l = s[i]
    if l in 'aeiou':
      c = 0
    else:
      c += 1
    if c >= n:
      nk = i+1-n
      t += nk - k + 1
      k = nk + 1
    ans += t
  print ans
