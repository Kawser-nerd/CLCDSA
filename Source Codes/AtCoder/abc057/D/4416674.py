N,A,B=map(int,input().split())
V=list(map(int,input().split()))
V=sorted(V,reverse=True)

def fac(n):
  if n<= 1: return 1
  return n*fac(n-1)
def c (a,b): 
  if b==0: return 1
  return fac(a)//fac(b)//fac(a-b)


print(sum(V[:A])/A)

if V.count(V[0]) >= A:
  ans=0
  for i in range(A, min(B+1,V.count(V[0])+1)):
    ans+=c(V.count(V[0]),i)
else:
  ans=c(V.count(V[A-1]), V[:A].count(V[A-1]))
print(ans)