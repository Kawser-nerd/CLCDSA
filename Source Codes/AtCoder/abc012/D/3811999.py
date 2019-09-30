N,M=map(int,input().split())
BUS=[list(map(int,input().split())) for i in range(M)]

Distance=[[float("inf") for i in range(N+1)] for j in range(N+1)]

for i ,j,t in BUS:
    Distance[i][j]=Distance[j][i]=t#????????????????.

for k in range(1,N+1):#k??????????Dis?????????
    for i in range(1,N+1):#?i?
        for j in range(i,N+1):#?j????????
            length=Distance[i][k]+Distance[j][k]
            if Distance[i][j]>length:
                Distance[i][j]=Distance[j][i]=length

ANS=float("inf")
for i in range(1,N+1):
    D=0
    for j in range(1,N+1):
        if i==j:
            continue
        if D<Distance[i][j]:
            D=Distance[i][j]

    if ANS>D:
        ANS=D

print(ANS)