n=int(input())
list=list(map(int,input().split()))
list.sort()
ans=0
for i in range(1,n+1):
  ans += (-1)**(i-1) * list[-i]
print(ans)