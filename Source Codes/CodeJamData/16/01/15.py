import sys

def sheep(N):
  if N==0: return "INSOMNIA"
  d=0;t=N
  while 1:
    for x in str(t): d|=1<<int(x)
    if d==1023: return t
    t+=N

case=0
for x in sys.stdin:
  if case>0:
    N=int(x.strip())
    print "Case #%d:"%case,sheep(N)
  case+=1
