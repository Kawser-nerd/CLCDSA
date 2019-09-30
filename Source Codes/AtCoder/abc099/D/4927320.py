N,C=map(int,input().split())

D=[list(map(int,input().split())) for i in range(C)]
grid=[list(map(int,input().split())) for i in range(N)]

a=[[0]*C for i in range(3)]


for i in range(N):
    for j in range(N):
        a[(i+j)%3][grid[i][j]-1]+=1

b=[[0]*C for i in range(3)]
for i in range(3):
    for j in range(C):
        b[i][j]=[ sum([ D[k][j] * a[i][k] for k in range(C)]), j]

b=[ sorted(b[i]) for i in range(3)]

ans=10**10
for i in range(3):
    for j in range(3):
        for k in range(3):
            if b[0][i][1]!=b[1][j][1] and b[1][j][1]!=b[2][k][1] and b[2][k][1]!=b[0][i][1]:
                ans=min(ans,b[0][i][0]+b[1][j][0]+b[2][k][0])

print(ans)