import math
n=int(input())
number=list(map(int,input().split()))
SUM=[]
sum=0
p=10**9 +7
x=math.factorial(n)%(10**9 +7)
for i in range(1,n+1):
  k=pow(i,p-2,p)
  sum+= (x*k)%p
  sum= sum%(p)
  SUM.append(sum)
ans=0
for i in range(n):
  ans+= number[i]*(SUM[n-1-i]+SUM[i]-x)
  ans=ans%(p)
print(ans)