N,G,E=[int(x) for x in input().split()]
P=[int(x) for x in input().split()]
itta=[0 for x in range(N)]
itta[0]=1
def dfs(gr,i):
    for j in range(len(gr[i])):
        if gr[i][j]==-1:
            del gr[i][j]
            return -1
        if itta[gr[i][j]]==0:
            itta[gr[i][j]]=1
            if dfs(gr,gr[i][j])==-1:
                del gr[i][j]
                return -1
    return 0

gr = [[] for x in range(N)]
for i in range(E):
    a,b=[int(x) for x in input().split()]
    gr[a].append(b)
    gr[b].append(a)
for p in P:
  gr[p].insert(0,-1)
ans = 0
while dfs(gr,0)==-1:
    itta=[0 for x in range(N)]
    itta[0]=1
    ans+=1
print(ans)