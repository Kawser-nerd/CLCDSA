import sys
def read_values():
  return map(int,raw_input().split())

for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')
  res = 0
  words = raw_input().strip().split()
  c = int(words.pop(0))
  tc = words[:c]
  words = words[c:]
  d = int(words.pop(0))
  td = words[:d]
  words = words[d:]
  n = int(words.pop(0))
  s = words.pop(0)
  t = []
  for i in range(n):
    t.append(s[i])
    if len(t)==1: continue
    # combined?
    combined = False
    j=0
    while j<c and not combined:
      if t[-1]==tc[j][0] and t[-2]==tc[j][1]:
        t.pop()
        t[-1] = tc[j][2]
        combined = True
      j += 1
    j=0
    while j<c and not combined:
      if t[-1]==tc[j][1] and t[-2]==tc[j][0]:
        t.pop()
        t[-1] = tc[j][2]
        combined = True
      j += 1
    # opposed?
    if not combined:
      opposed = False
      j = 0
      while j<d and not opposed:
        if t[-1]==td[j][0] and td[j][1] in t[:-1]:
          opposed = True
          t = []
        j += 1
      j = 0
      while j<d and not opposed:
        if t[-1]==td[j][1] and td[j][0] in t[:-1]:
          opposed = True
          t = []
        j += 1
  res = str(t).replace('\'','')
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')
