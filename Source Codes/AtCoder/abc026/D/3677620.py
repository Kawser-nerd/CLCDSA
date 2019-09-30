from math import pi,sin,acos,ceil
A,B,C=map(int,input().split())
up=0
if A/(B*C*pi)>1:
  l=(100-B)/A
  r=(100+B)/A
else:
  d=acos(-A/(B*C*pi))/(C*pi)
  n=ceil(C*((100-B)/A+d)/2)
  l=-d+2*n/C
  r=d+2*n/C

def f(x):
  return A*x+B*sin(C*pi*x)

for i in range(150):
  m=(l+r)/2
  if f(m)>=100:
    r=m
  else:
    l=m
  
print(m)