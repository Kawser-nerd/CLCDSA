n=int(input())

ans=1000000000000000000000
for i in range(1,1001):
  for j in range(1,1001):
    if n>=i*j:
      #print(n,i,j)
      tmpans=abs(i-j)+(n-i*j)
      if ans>tmpans:
        ans=tmpans
print(ans)