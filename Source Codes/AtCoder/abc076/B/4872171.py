n=int(input())
k=int(input())
ans=1
for i in range(n):
  if ans>=k:
    ans+=k
  else:
    ans*=2
print(ans)