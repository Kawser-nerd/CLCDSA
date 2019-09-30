n,m=map(int,input().split())

A=[list(map(int,input().split())) for _ in range(n)]

B=[list(map(int,input().split())) for _ in range(m)]


for a in A:
    D=[]
    for i in range(m):
        D.append([abs(a[0]-B[i][0])+abs(a[1]-B[i][1]),i+1])
    D=sorted(D,key=lambda x:(x[0],x[1]))
    print(D[0][1])