C=input()
for c in range(C):
  N,K,B,T=map(int,raw_input().split())
  X=map(int,raw_input().split())
  V=map(int,raw_input().split())
  swich=0
  done=0
  skip=0
  for i in range(N):
    if done==K: break
    if(V[-i-1]*T>=B-X[-i-1]):
      done+=1
      swich+=skip
    else: skip+=1
  if(done==K): print "Case #%d: %d"%(c+1,swich)
  else: print "Case #%d: IMPOSSIBLE"%(c+1)

