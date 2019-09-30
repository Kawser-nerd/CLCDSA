#!/usr/bin/python
def valid(sol,shakes):
   for c in shakes:
      i=0 
      while i<len(c):
         if c[i+1]==sol[c[i]-1]:
            break
         i+=2
      if i>=len(c):
         return False
   return True
   
def solve(N,shakes):
   sol=[0]*N
   changed=True
   while(changed):
      changed=False
      for c in shakes:
         if len(c)==2 and c[1]==1 and sol[c[0]-1]==0:
            changed=True
            sol[c[0]-1]=1
            for j in xrange(len(shakes)):
               s=shakes[j]
               i=0 
               while i<len(s):
                  if s[i]==c[0] and s[i+1]==0:
                     s=s[:i]+s[i+1:]
                     s=s[:i]+s[i+1:]
                  i+=2
               shakes[j]=s   
   if valid(sol,shakes):
      return " ".join(map(str,sol))
   return "IMPOSSIBLE"   
   
if __name__ == "__main__":
   import sys
   sys.setrecursionlimit(1000000)
   C = int(sys.stdin.readline())   
   for i in xrange(C):
      N = int(sys.stdin.readline())   #flavors
      M = int(sys.stdin.readline())   #customers
      shakes=[]
      for j in xrange(M):
         shakes.append(map(int,sys.stdin.readline().split())[1:])
      print "Case #%d: %s" %(i+1,solve(N,shakes))

