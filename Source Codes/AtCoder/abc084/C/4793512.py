n=int(input())
c=[]
s=[]
f=[]
for i in range(n-1):
  x,y,z=map(int,input().split())
  c.append(x)
  s.append(y)
  f.append(z)
def needtime(t,i):
  if s[i]>=t:
    T=s[i]
  else:
    if (t-s[i])%f[i]==0:
      T=t
    else:
      T=t+f[i]-(t-s[i])%f[i]
  return T+c[i]
for i in range(n):
  t=0
  for j in range(i,n-1):
    t=needtime(t,j)
  print(t)