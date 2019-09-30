t=input()
parties="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for j in xrange(t):
  n=input()
  p=map(int,raw_input().strip().split())
  res="Case #"+str(j+1)+":"
  while max(p)>0:
    res+=" "
    m=max(p)
    c=p.count(m)
    pty=p.index(m)
    res+=parties[pty]
    p[pty]-=1
    if c==2:
      pty=p.index(m)
      res+=parties[pty]
      p[pty]-=1
  print res
