import sys
from collections import defaultdict

def test(words, c, denied):
  for word in words:
    if c in word and not set(word).intersection(denied):
      return True
  return False

T = int(sys.stdin.readline())
for no_t in xrange(1, T + 1):
  N, M = [int(x) for x in sys.stdin.readline().split()]
  words = [sys.stdin.readline().strip() for x in xrange(N)]
  lists = [sys.stdin.readline().strip() for x in xrange(M)]
  sol = []
  S = defaultdict(list)
  for word in words:
    letters = list(set(word))
    for i in xrange(0, 1 << len(letters)):
      s = word
      for j in xrange(len(letters)):
        if i & (1 << j):
          s = s.replace(letters[j], '_')
      for c in letters:
        S[s].append(set(word))
  for l in lists:
    tmp = -1
    res = ''
    for word in words:
      s = '_' * len(word)
      i = 0
      aux = 0
      denied = set()
      while '_' in s:
        if test(S[s], l[i], denied):
          if l[i] in word:
            xx = []
            for aa, bb in zip(s, word):
              if aa != '_':
                xx.append(aa)
              elif bb == l[i]:
                xx.append(bb)
              else:
                xx.append('_')
            s = ''.join(xx)
          else:
            denied.add(l[i])
            aux += 1
        else:
            denied.add(l[i])
        i += 1
      if aux > tmp:
        tmp = aux
        res = word
    sol.append(res)
  print 'Case #%s: %s' % (no_t, ' '.join(sol))
