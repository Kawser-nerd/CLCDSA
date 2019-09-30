N=int(input())
A=[int(input())for _ in[0]*N]
r=0;i=0
for _ in [0]*N:
  i=A[i]-1;r+=1
  if i==1:print(r);exit()
print(-1)