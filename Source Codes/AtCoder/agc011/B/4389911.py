n=int(input())
t=sorted(map(int, input().split()),reverse=True)
sm=sum(t)
ans=0
for i in t:
    sm-=i
    ans+=1
    if i>sm*2:
        break
print(ans)