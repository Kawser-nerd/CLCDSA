s=[i for i in input()]
n=int(input())
for _ in range(n):
  r,l=map(int,input().split())
  r,l=r-1,l-1
  for i in range((l-r+1)//2):
    s[r+i],s[l-i]=s[l-i],s[r+i]
ans=""
for i in s:
  ans+=i
print(ans)