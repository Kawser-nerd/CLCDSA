N,x=map(int,input().split())
A=[int(a) for a in input().split()]
s=0
for i in range(1,N):
  t=A[i-1]+A[i]
  if t>x:
    s+=t-x
    A[i]=max(0,A[i]+x-t)
    
print(s)