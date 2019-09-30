def solve():
  s = raw_input()
  howmany = [0] * 10

  howmany[0] = s.count('Z')
  howmany[2] = s.count('W')
  howmany[6] = s.count('X')
  howmany[8] = s.count('G')
  howmany[7] = s.count('S') - howmany[6]
  howmany[5] = s.count('V') - howmany[7]
  howmany[4] = s.count('F') - howmany[5]
  howmany[3] = s.count('H') - howmany[8]
  howmany[1] = s.count('O') - howmany[0] - howmany[2] - howmany[4]
  howmany[9] = s.count('I') - howmany[5] - howmany[6] - howmany[8]

  ans = []
  for i in xrange(10):
    ans += [i] * howmany[i]
  ans.sort()
  return ''.join(map(str, ans))

T = input()
for i in xrange(T):
  print 'Case #%d: %s' % (i + 1, solve())
