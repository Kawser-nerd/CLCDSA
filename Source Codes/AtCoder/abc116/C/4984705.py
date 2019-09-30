import sys

def f(k):
  global N,h,update
  if k==N:
    return -1
  if h[k]==0:
    return k
  else:
    h[k]-=1
    update=True
    f(k+1)


update=False
N=int(input())
h=list(map(int,input().split(" ")))
r=0
s=0

try:
  while True:
    if h[s]!=0:
      break
    s+=1
except Exception:
  print(0)
  sys.exit(0)

while True:
  f(s)
  if update:
    r+=1
    while s!=N-1 and h[s]==0:
      s+=1
    update=False
  else:
    break

print(r)