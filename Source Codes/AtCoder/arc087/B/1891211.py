import sys
sys.setrecursionlimit(10000)
inp=list(map(len,input().split("T")))
inx,iny=list(map(int,input().split()))
memo={}
def tg(g,n,t):
 g.sort()
 g.reverse()
 def tn(g,n,t):
  if (tuple(g),n,t) in memo:
   return memo[(tuple(g),n,t)]
  if g==[]:
   if n==t:
    return True
   else:
    return False
  if n<t:
   z=tn(g[1:],n+g[0],t)
   memo[(tuple(g),n,t)]=z
   return z
  else:
   z=tn(g[1:],n-g[0],t)
   memo[(tuple(g),n,t)]=z
   return z
 return tn(g,n,t)
 
if tg(inp[1::2],0,iny)and tg(inp[2::2],inp[0],inx):
 print("Yes")
else:
 print("No")