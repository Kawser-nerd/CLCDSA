n,m=[int(i) for i in input().split()]
#???????
rinsetsu=[[0 for _ in range(n)] for _ in range(n)]
for i in range(m):
    a,b=[int(j) for j in input().split()]
    rinsetsu[a-1][b-1]=1
    rinsetsu[b-1][a-1]=1
visited=[False]*n
ans=0
flag=True
#????????1?????????????????????
#??????????(???)?????
while flag:
    flag=False
    for i in range(n):
        if not visited[i] and sum(rinsetsu[i])==1:
            visited[i]=True
            ans+=1
            flag=True
            for j in range(n):
                if rinsetsu[i][j]==1:
                    rinsetsu[j][i]=0
print(ans)