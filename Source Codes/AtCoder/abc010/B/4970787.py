n=int(input())
ans=0
for a in map(int,input().split()):
  while a%2==0 or a%3==2:
    ans+=1
    a-=1
print(ans)