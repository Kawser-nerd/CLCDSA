import sys
def read_values():
  return map(int,raw_input().split())

for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')
  n = input()
  t = map(int,raw_input().split())
  u = t[:]
  u.sort()
  res = sum([u[i]!=t[i] for i in range(n)])
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')
