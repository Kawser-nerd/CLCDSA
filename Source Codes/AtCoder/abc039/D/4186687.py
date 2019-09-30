import numpy as n
h,w=map(int,input().split())
s=n.array([list(input()) for i in range(h)])
def sh(p,q,a):
  for i in range(h):
    for j in range(w):
      if p[i,j]==a:q[max(0,i-1):i+2,max(0,j-1):j+2]=a
  return q
t=sh(s,n.copy(s),'.')
e='possible'
p=print
if (s==sh(t,n.copy(t),'#')).all():
  p(e)
  for i in t:p(*i,sep='')
else:p('im'+e)