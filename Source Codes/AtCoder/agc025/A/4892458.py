n=int(input())
ans=10**5
for a in range(1,n//2+1):
  b=n-a
  ans=min(ans,a%10+a//10%10+a//100%10+a//1000%10+a//10000%10+b%10+b//10%10+b//100%10+b//1000%10+b//10000%10)
print(ans)