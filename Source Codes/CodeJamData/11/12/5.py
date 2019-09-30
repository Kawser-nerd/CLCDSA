def ints():
  return map(int, raw_input().split())

def worse_option(p1, p2, ranks):
  # returns whether p1 is worse than p2
  if p1[0] == p2[0]: # same number of steps
    return ranks[p1[1]] < ranks[p2[1]] # pick first from dictionary
  return (p1[0] > p2[0])

def solve(D, el):
  worst = {}
  ranks = {}
  for i,v in enumerate(D):
    ranks[v] = i
  for d in D:
    worst[d] = (0, d, '') # num steps, worst word, guess to make
  for c in reversed(el):
    to_reduce = []
    for word in worst:
      if c in word:
        to_reduce.append(word)
    for word in to_reduce:
      option = worst.pop(word)
      new_word = word.replace(c, '_')
      if new_word in worst and worst[new_word][2] != c:
        x = worst[new_word]
        worst[new_word] = (x[0] + 1, x[1], c) # another guess to get wrong
      if new_word not in worst or worse_option(option, worst[new_word], ranks):
        x = option
        worst[new_word] = (x[0], x[1], c)
  worst_option = (-1, "")
  for v in worst.itervalues():
    if worse_option(v, worst_option, ranks):
      worst_option = v
  return worst_option[1]

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
  N, M = ints()
  D = []
  L = []
  for i in xrange(N):
    D.append(raw_input())
  for i in xrange(M):
    L.append(raw_input())
  results = [solve(D, el) for el in L]
  res = ' '.join(results)
  print "Case #%d: %s" % (case_num, res)
