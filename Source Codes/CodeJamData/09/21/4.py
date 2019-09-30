def compute(s):
  root = {}
  cur = root
  i = 0
  while i < len(s):
    c = s[i]
    if c == ' ':
      i += 1
      continue
    if c == '(':
      if 'r' in cur:
        cur['l'] = {'p': cur}
        cur = cur['l']
      else:
        cur['r'] = {'p': cur}
        cur = cur['r']
      i += 1
      p = ''
      while s[i] != ' ' and s[i] != ')':
        p += s[i]
        i += 1
      cur['v'] = float(p)
      if s[i] != ')':
        p = ''
        i += 1
        while s[i] != '(':
          p += s[i]
          i += 1
        cur['a'] = p
    if s[i] == ')':
      cur = cur['p']
      i += 1
  return root

root = {}
f = open('p1.in', 'r')
T = int(f.readline())
for x in range(T):
  print 'Case #%s:' % (x + 1)
  L = int(f.readline())
  s = ''
  for i in range(L):
    s += f.readline()[:-1]
  while True:
    old = s
    s = s.replace('  ',' ')
    if old == s:
      break
  s = s.replace(' )', ')')
  s = s.replace(') ', ')')
  s = s.replace('( ', '(')
  s = s.replace(' (', '(')
  root = compute(s)
  n = int(f.readline())
  for ii in range(n):
    line = f.readline()[:-1].split(' ')
    features = set(line[2:])
    cur = root['r']
    p = 1.0
    while 'r' in cur:
      p *= cur['v']
      if cur['a'] in features:
        cur = cur['r']
      else:
        cur = cur['l']
    print '%.7f' % (p * cur['v'])

