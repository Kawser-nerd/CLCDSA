def habatu():
    n,m=map(int,input().split())
    gin=[[0 for i in range(n)]for i in range(n)]
    for i in range(m):
        x,y=map(int,input().split())
        gin[x-1][y-1]=1
        gin[y-1][x-1]=1
    gg=[[i] for i in range(n)]
    for i in gg:
        for j in range(n):

            for x in i:
                d=True

                if gin[x][j]==0:
                    d=False
                    break
            if d:
                i+=[j]
        gg[i[0]]=i
    gg=list(map(lambda x: len(x),gg))
    return max(gg)
print(habatu())