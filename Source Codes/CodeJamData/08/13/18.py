import sys
N=int(input())

def choose(n,k):
  res = 1
  for i in range(k):
    res*=n-i
    res/=i+1
  return res

for step in range(N):
  n=int(input())
  res = 0
  for i in range(n/2+1):

    res += 2*choose(n,2*i)*3**(n-2*i)*5**i
    res = res%1000
  if(res>0):
    res -=1
  else:
    res=999
  sys.stderr.write(str(step+1)+' ')
  print 'Case #%s: %s'%(step+1,str(res).zfill(3))
sys.stderr.write('\n')
