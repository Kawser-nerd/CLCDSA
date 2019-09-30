Xs,Ys,Xt,Yt = map(int,input().split())
n = int(input())
p = [(Xs,Ys,0),(Xt,Yt,0)]
for i in range(2,n+2):
    p.append(tuple(map(int,input().split())))
cost = [[0]*(n+2)for i in range(n+2)]

for i in range(n+2):
    for j in range(i,n+2):
        cost[i][j] = cost[j][i] =  max(((p[i][0]-p[j][0])**2+(p[i][1]-p[j][1])**2)**0.5 - p[i][2] - p[j][2],0)
cost = tuple(cost)
n += 2
s = 0
#??s???????????
#n:???,?w:???, cost[u][v] : ?uv????(????????inf)
d = [float("inf")] * n
used = [False] * n
d[s] = 0
    
while True:
    v = -1
    #?????????????????????????
    for i in range(n):
        if (not used[i]) and (v == -1):
           v = i
        elif (not used[i]) and d[i] < d[v]:
            v = i
    if v == -1:
           break
    used[v] = True
           
    for j in range(n):
           d[j] = min(d[j],d[v]+cost[v][j])
print(d[1])