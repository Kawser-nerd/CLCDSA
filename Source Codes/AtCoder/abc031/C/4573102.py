n=int(input())
A=list(map(int,input().split()))
ans=-100
for i in range(n):
  tmp=-1000
  J=-100
  for j in range(n):
    if i==j:
      continue
    l,r= sorted([i,j])
    if sum(A[l+1:r+1:2])>tmp:
      J=j
      tmp=sum(A[l+1:r+1:2])
  l,r=sorted([i,J])
  ans=max(sum(A[l:r+1:2]),ans)
print(ans)