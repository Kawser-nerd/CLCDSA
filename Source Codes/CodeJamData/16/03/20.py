import sys
ssw=sys.stdout.write

case=0
for x in sys.stdin:
  if case>0:
    [N,J]=[int(y) for y in x.strip().split()]
    print "Case #%d:"%case
    assert (N&1)==0 and J<=2**(N/2-1)
    for j in range(J):
      s='1'
      for k in range(N/2-1): s+=str(j>>k&1)*2
      s+='1'
      ssw(s)
      for k in range(2,11): ssw(' '+str(k+1))
      print
  case+=1
