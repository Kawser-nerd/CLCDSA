def ints():
  return map(int, raw_input().split())

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
  N, = ints()
  values = ints()
  total = reduce(lambda a, b: a^b, values)
  if total:
    res = "NO"
  else:
    res = sum(values) - min(values)
  print "Case #%d: %s" % (case_num, res)
