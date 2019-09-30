t=input()
for i in xrange(t):
  j,p,s,k=map(int,raw_input().strip().split())
  if k>=s:
    print "Case #"+str(i+1)+": "+str(j*p*s)
    for jj in xrange(1,j+1):
      for pp in xrange(1,p+1):
        for ss in xrange(1,s+1):
          print jj,pp,ss
  elif k>=p:
    print "Case #"+str(i+1)+": "+str(j*p*k)
    for jj in xrange(1,j+1):
      for pp in xrange(1,p+1):
        for ss in xrange(1,k+1):
          print jj,pp,ss
  else:
    print "Case #"+str(i+1)+": "+str(j*p*k)
    mods=[]
    for ss in xrange(1,k+1):
      mods.append((2+ss)%p)
    mods=set(mods)
    for jj in xrange(1,j+1):
      for pp in xrange(1,p+1):
        for ss in xrange(1,p+1):
          if (jj+pp+ss)%p in mods:
            print jj,pp,ss
