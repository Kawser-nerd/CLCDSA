n,c,k=[int(i) for i in input().split()]
people=list(reversed(sorted([int(input()) for _ in range(n)])))
start=people[0]
cnt=1
ans=1
for i in people[1:]:
    if start-i<=k and i>=start-k and cnt<c:
        cnt+=1
    else:
        cnt=1
        ans+=1
        start=i
print(ans)