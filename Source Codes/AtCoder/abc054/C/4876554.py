z,m=map(int,input().split());a=[[],[]];ans=0
for i in range(m):aa,bb=map(int,input().split());a[0].append(aa);a[1].append(bb)
def d(n,nl,ml):
  if sorted(nl+[n])==[i+1for i in range(z)]:return 1
  if n in nl:return 0
  l=len(ml[0]);ans=0
  for i in range(l):
    c=[ml[0][:i]+ml[0][i+1:],ml[1][:i]+ml[1][i+1:]]
    if ml[0][i]==n:ans+=d(ml[1][i],nl+[n],c)
    if ml[1][i]==n:ans+=d(ml[0][i],nl+[n],c)
  return ans
for i in range(m):
  if a[0][i]==1:
    c=[a[0][:i]+a[0][i+1:],a[1][:i]+a[1][i+1:]]
    ans+=d(a[1][i],[1],c)
print(ans)