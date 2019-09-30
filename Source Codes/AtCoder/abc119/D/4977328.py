import bisect
def adj(x,ks):
  idx=bisect.bisect_left(ks,x)
  return ks[idx-1],ks[idx]

def distance(x,a,b):
  return min(abs(x-a),abs(x-b))+abs(a-b)

def helper(x,ss,ts):
  temp1,temp2=adj(x,ts)
  shin1,shin2=adj(x,ss)
  t=min(distance(x,temp1,shin1),distance(x,temp2,shin1),distance(x,temp1,shin2),distance(x,temp2,shin2))
  return t

a,b,q=map(int,input().split())
t=10**20
ss=[-t]+[int(input()) for _ in range(a)]+[t]
ts=[-t]+[int(input()) for _ in range(b)]+[t]
qs=[int(input()) for _ in range(q)]
for x in qs:
  print(helper(x,ss,ts))