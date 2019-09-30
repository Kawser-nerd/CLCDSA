m=lambda:map(int,input().split())
a,b,c,k=m()
s,t=m()
p=a*s+b*t
if (s+t)>=k:
  p-=(s+t)*c
print(p)