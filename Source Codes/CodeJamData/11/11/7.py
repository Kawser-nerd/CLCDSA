def ints():
  return map(int, raw_input().split())

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
  n, pd, pg = ints()
  poss = n >= 100 or any((pd * d) % 100 == 0 for d in xrange(1, n+1))
  if pg in (0, 100) and pg != pd:
    poss = False
  res = "Possible" if poss else "Broken"
  print "Case #%d: %s" % (case_num, res)
