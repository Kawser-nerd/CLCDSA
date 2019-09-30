import sys

case=0
for x in sys.stdin:
  if case>0:
    S=x.strip()
    print "Case #%d:"%case,sum([(S+'+')[i+1]!=S[i] for i in range(len(S))])
  case+=1
