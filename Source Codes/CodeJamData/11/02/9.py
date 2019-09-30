def ints():
  return map(int, raw_input().split())

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
  line = raw_input().split()[::-1]

  comb = {}
  opp = set()
  L = []

  C = int(line.pop())
  for i in xrange(C):
    s = line.pop()
    x, y, z = list(s)
    comb[(x, y)] = z
    comb[(y, x)] = z
  D = int(line.pop())
  for i in xrange(D):
    s = line.pop()
    x, y = list(s)
    opp.add((x, y))
    opp.add((y, x))
  N = int(line.pop())
  S = line.pop()
  for char in S:
    if L and (char, L[-1]) in comb:
      last = L.pop()
      L.append(comb[(char, last)])
    elif any((char, c) in opp for c in L):
      L = []
    else:
      L.append(char)
  print "Case #%d: [%s]" % (case_num, ", ".join(L))
