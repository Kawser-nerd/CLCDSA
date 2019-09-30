import math

# ??
N=int(input())

# ??
s=0

l=[]
for i in range(N):
  l.append(int(input()))

# ???
l=sorted(l,key=lambda x:x,reverse=True)

for i in range(N):
  a=l[i]
  if i%2==0:
    s+=a*a*math.pi
  else:
    s-=a*a*math.pi

# ??
print(s)