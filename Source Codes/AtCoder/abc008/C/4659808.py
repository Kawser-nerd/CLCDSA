n=int(input())
c=[int(input()) for _ in range(n)]

ans=0
for i in range(n): #c[i]
  k=-1
  for j in range(n):
    if c[i]%c[j]==0:
      k+=1
  if k%2==0:
    ans+=(k+2)/(2*k+2)
  else:
    ans+=1/2
    
print(ans)