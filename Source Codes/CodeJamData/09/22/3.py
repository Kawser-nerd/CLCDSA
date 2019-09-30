f = open('a.in', 'r')
T = int(f.readline())
for x in range(T):
  s = f.readline()
  s= s[:-1]
  n = len(s)
  sol = 0
  maxx = s[-1]
  for i in range(n - 1, -1, -1):
    if maxx > s[i]:
      break
    else:
      maxx = s[i]
  if maxx > s[i]:
    for j in range(i+1, n):
      if s[j] > s[i]:
        if maxx > s[j]:
          maxx = s[j]
    rest = [c for c in s[i:]]
    rest.remove(maxx)
    sol = s[:i] + maxx + ''.join(sorted(rest))
  else:
    minn = min([c for c in s if c != '0'])
    rest = [c for c in s]
    rest.remove(minn)
    sol = minn + '0' + ''.join(sorted(rest))
  print 'Case #%s: %s' % (x + 1, sol)
