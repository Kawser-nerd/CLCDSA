n=int(input())
a=list(map(int,input().split()))
ans=0
stack=1
for i in range(1,n):
  if a[i-1]<a[i]:
    stack+=1
  else:
    ans+=stack*(stack-1)//2
    stack=1
ans+=stack*(stack-1)//2
print(ans+n)