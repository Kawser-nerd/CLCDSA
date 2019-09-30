import sys
def read_values():
  return map(int,raw_input().split())

for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')
  n = input()
  t = map(int,raw_input().split())
  t.sort()
  s = 0
  for i in range(n):
    s = s ^ t[i]
  if s==0:
    res = sum(t[1:])
  else:
    res = 'NO'
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')
