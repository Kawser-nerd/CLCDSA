def yakusu(m):
  cnt=1
  for i in range(1,(m//2)+1):
    if m%i==0:
      cnt+=1
  return cnt
ans=0
n=int(input())
for j in range(1,n+1):
  if yakusu(j)==8 and j%2!=0:
    ans+=1
print(ans)