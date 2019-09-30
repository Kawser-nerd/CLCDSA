inf=float('inf')
n, m=map(int, input().split())
abc=[list(map(int, input().split())) for i in range(m)]
abc=[[ai[0]-1, ai[1]-1, -ai[2]] for ai in abc]
d=[inf]*n
d[0]=0
for i in range(n):
    flag=False
    for abci in abc:
        if d[abci[1]]>d[abci[0]]+abci[2]:
            flag=True
            d[abci[1]]=d[abci[0]]+abci[2]
            if i==n-1 and abci[1]==n-1:
                print('inf')
                exit()

print(-d[n-1])