import sys

L=30
normal=[0,1]
surprise=[0,1]
for i in range(2,L+1):
  normal.append(i/3+((i%3)>0))
  surprise.append(2+(i-2)/3)
  
for case_index in range(1, 1+input()):
  sys.stderr.write(str(case_index)+' ')
  v=map(int,raw_input().split())
  N=v.pop(0)
  S=v.pop(0)
  p=v.pop(0)
  res = 0
  a=0
  for i in range(N):
    if p<=normal[v[i]]:
      res+=1
    elif surprise[v[i]]==p:
      a+=1
  if S<a:
    a=S
  res += a
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')

