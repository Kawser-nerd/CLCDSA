
def gcd(p,q):
  if p==0:
    return q
  if q<p:
    return gcd(q,p)
  return gcd(q%p,p)

def isp2(x):
  if x==1:
    return True
  if x%2==1:
    return False
  return isp2(x/2)

def lp2(x):
  d = 1
  while d<=x:
    d*=2
  return d/2
  
def lg2(x):
  d = 1
  c = 1
  while d<=x:
    d*=2
    c += 1
  return c-1
  

T = int(raw_input())
for t in range(T):
  p,q = map(int,raw_input().split('/'))
  g =gcd(p,q)
  p/=g
  q/=g
  if not isp2(q):
    ans = 'impossible'
  else:
    ans = lg2(q/lp2(p))-1
  print "Case #"+str(t+1)+": "+str(ans)