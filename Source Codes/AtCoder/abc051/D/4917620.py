#D??
N,M=map(int,input().split())

def warshall_floyd(dist,n):
    #dist[i][j]: i??j??????
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])
    return dist

dist = [[float("inf") for i in range(N)] for i in range(N)] 
#dist[u][v] : ?uv????(????????inf)
xyz=[]
for i in range(M):
    x,y,z = map(int,input().split())
    xyz.append([x-1,y-1,z])
    dist[x-1][y-1] = z
    dist[y-1][x-1] = z
for i in range(N):
    dist[i][i] = 0 #??????????????
wf=warshall_floyd(dist,N)
ans=M
for i in range(M):
    j=0
    flag=0
    for j in range(N):
        if wf[j][xyz[i][0]] + xyz[i][2] == wf[j][xyz[i][1]]:
            flag=1
            break
    if flag == 1:
        ans-=1
    flag=0
print(ans)