for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  N = input()
  sents = []
  words = set()
  for _ in xrange(N):
    sents.append(raw_input().split())
    words.update(sents[-1])
  words = list(words)
  masks = []
  for sent in sents:
    m = 0
    for word in sent:
      m |= (1 << words.index(word))
    masks.append(m)
  ans = 1e100
  for i in xrange(1<<(N-2)):
    en = masks[0]
    fr = masks[1]
    for j in xrange(N-2):
      if i & (1 << j):
        en |= masks[2+j]
      else:
        fr |= masks[2+j]
    ans = min(ans, bin(en&fr).count('1'))
  print ans
