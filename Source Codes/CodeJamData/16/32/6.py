t=input()
for j in xrange(t):
  b,m=map(int,raw_input().strip().split())
  if m>2**(b-2):
    print "Case #"+str(j+1)+": IMPOSSIBLE"
  else:
    print "Case #"+str(j+1)+": POSSIBLE"
    #line 2 is a 0, then m-1 written in binary with leading zeroes if needed,
    #then a 1.
    m-=1
    res="1"
    for k in xrange(b-2):
      if m%2==1:
        res="1"+res
        m-=1
      else:
        res="0"+res
      m/=2
    print "0"+res
    #other lines have all the slides, even if we can't reach some of them.
    for i in xrange(1,b):
      print "0"*(i+1)+"1"*(b-1-i)
