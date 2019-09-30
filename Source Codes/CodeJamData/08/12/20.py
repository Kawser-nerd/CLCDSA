import sys

sys.stdin = open("B.in","r")
sys.stdout = open("B.out","w")
def bit(n):
      cnt = 0 
      while n!=0:
            cnt+=1
            n = n&(n-1)
      return cnt

C = int(raw_input())
for T in xrange(C):
      N = int(raw_input())
      M = int(raw_input())

      likes = {}
      
      for i in xrange(M):
            likes[i] = []
            temp = raw_input().strip().split()
            num = int(temp[0])
            for j in xrange(num):
                  likes[i].append( (int(temp[1+2*j]),int(temp[2+2*j]) ))
      possible = []
      for k in xrange(2**N):
             satis = [0]*M
             for h in xrange(0,N):
                   if k&(1<<h):
                         for i in xrange(0,M):
                               if (h+1,1) in likes[i]:
                                     satis[i] = 1
                   else:
                         for i in xrange(0,M):
                               if (h+1,0) in likes[i]:
                                     satis[i] = 1
             if all(satis):
                   possible.append(k)
      
      if possible:
            res = 0
            cnt = bit(possible[0])
            for i in xrange(len(possible)):
                  if cnt > bit(possible[i]):
                        res = i
                        cnt = bit(possible[i])
            temp = possible[res]
            res  = ""
            for i in xrange(N-1,-1,-1):
                  if temp&(1<<i):
                        res = "1 "+res
                  else:
                        res = "0 "+res
            print "Case #%s: %s" % (str(T+1),str(res.strip()))
      else:
            print "Case #%s: IMPOSSIBLE" % (str(T+1))
            
sys.stdin.close()
sys.stdout.close()
