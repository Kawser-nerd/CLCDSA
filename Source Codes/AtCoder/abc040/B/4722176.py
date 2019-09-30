n=int(input())
ans=10**18
for i in range(1,321):
  if i*i>n:
    break
  ans=min(ans,n//i - i +n%i)
print(ans)