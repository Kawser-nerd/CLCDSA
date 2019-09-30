t=input()
for j in xrange(t):
  d=input()
  pancakes=map(int,raw_input().strip().split())
  mintime=1000
  for maxstacksize in xrange(max(pancakes),0,-1):
    time=maxstacksize
    for p in pancakes:
      time+=(p-1)//maxstacksize
    if time<mintime:
      mintime=time
  print "Case #"+str(j+1)+": "+str(mintime)
