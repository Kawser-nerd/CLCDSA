
import sys

def choose(n,k):
  if k>n:
    return 0
  res=1
  for i in range(k):
    res*=n-i
    res/=i+1
  return res

for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')  
  C,N=map(int,raw_input().split())
  r = [0]*(C+1)
  r[N]=1
  M = [ [ 0 for _ in range(C+1)] for _ in range(C+1) ]
  for a in range(N,C+1):
    for b in range(a,a+N+1):
      if b<=C:
        M[a][b] = choose(a,N-b+a)*choose(C-a,b-a)/float(choose(C,N))
  res = r[C]
  for step in range(2000):
    u = [0]*(C+1)
    for l in range(C+1):
      for k in range(C+1):
        u[l] += r[k]*M[k][l]
    res += (step+2)*(u[C]-r[C])
    r=u
  print 'Case #%s: %.7f'%(case_index,res)

sys.stderr.write('\n')
