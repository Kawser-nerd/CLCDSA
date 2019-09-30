#full quaternion multiplication table
multq={}
products=(("1","1","1"),
          ("1","i","i"),
          ("1","j","j"),
          ("1","k","k"),
          ("i","1","i"),
          ("i","i","-1"),
          ("i","j","k"),
          ("i","k","-j"),
          ("j","1","j"),
          ("j","i","-k"),
          ("j","j","-1"),
          ("j","k","i"),
          ("k","1","k"),
          ("k","i","j"),
          ("k","j","-i"),
          ("k","k","-1"))
for a,b,c in products:
  multq[(a,b)]=c
  multq[("-"+a,"-"+b)]=c
  if len(c)==2:
    multq[("-"+a,b)]=c[-1]
    multq[(a,"-"+b)]=c[-1]
  else:
    multq[("-"+a,b)]="-"+c
    multq[(a,"-"+b)]="-"+c

t=input()
for j in xrange(t):
  l,x=map(int,raw_input().strip().split())
  s=raw_input().strip()
  if x>=12:
    #Four copies of anything multiply to 1, so we can reduce mod 4, and
    #at most we need 4 copies in each of the first two splits.
    x=8+x%4
  s=s*x
  state=0
  #First we look for any initial sequence which multiplies to i.
  #After that, we look for an initial sequence which multiplies to i*j=k
  #At the end, we look for the total product to be i*j*k=-1.
  p="1"
  for q in s:
    p=multq[(p,q)]
    if state==0:
      if p=="i":
        state=1
    elif state==1:
      if p=="k":
        state=2
  if state==2 and p=="-1":
    print "Case #"+str(j+1)+": YES"
  else:
    print "Case #"+str(j+1)+": NO"
