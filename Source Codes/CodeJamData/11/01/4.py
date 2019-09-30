import sys
def read_values():
  return map(int,raw_input().split())

for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')
  res = 0
  words = raw_input().strip().split()
  n = int(words.pop(0))
  x = [1,1]
  t = [0,0]
  color = ['O','B']
  for i in range(n):
    r = words.pop(0)
    p = int(words.pop(0))
    which = color.index(r)
    res = max(res+1,t[which]+abs(x[which]-p)+1)
    x[which]=p
    t[which]=res

  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')
