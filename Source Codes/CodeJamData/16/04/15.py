import sys

def fract(K,C,S):
  if S*C<K: return "IMPOSSIBLE"
  l=[]
  for c in range(0,K,C):
    t=0
    for i in range(C): t=t*K+min(c+i,K-1)
    l.append(t)
  return ' '.join([str(i+1) for i in l])

case=0
for x in sys.stdin:
  if case>0:
    [K,C,S]=[int(y) for y in x.strip().split()]
    print "Case #%d:"%case,fract(K,C,S)
  case+=1
