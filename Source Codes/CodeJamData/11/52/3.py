def ints():
  return map(int, raw_input().split())

def solve(seq, limit):
  x0 = seq[0]
  seq = map(lambda x: x - x0, seq)
  M = seq[-1] + 1
  limit = min(limit, M)
  counts = [0] * M
  for x in seq:
    counts[x] += 1
  for lim in xrange(limit, 0, -1):
    copy_counts = [count for count in counts]
    if can_solve(copy_counts, lim, M):
      return lim
  return 1

def can_solve(counts, lim, M):
  endcounts = [0] * M
  for i in xrange(M):
    while counts[i]:
      if i > 0 and endcounts[i-1] > 0:
        # append to existing seq
        counts[i] -= 1
        endcounts[i-1] -= 1
        endcounts[i] += 1
      else:
        # start a new sequence
        if i+lim > M:
          return False
        for j in xrange(i, i+lim):
          if counts[j] == 0:
            return False
          counts[j] -= 1
        endcounts[i+lim-1] += 1
  return True

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
  cards = ints()[1:]
  N = len(cards)
  cards.sort()
  subseq = []
  lower = 0
  while lower < N:
    upper = lower
    while upper < N-1 and cards[upper + 1] <= cards[upper] + 1:
      upper += 1
    subseq.append(cards[lower:upper+1])
    lower = upper + 1
  if N == 0:
    res = 0
  else:
    res = min(seq[-1] - seq[0] + 1 for seq in subseq)
    for seq in subseq:
      res = min(res, solve(seq, res))
  print "Case #%d: %d" % (case_num, res)
