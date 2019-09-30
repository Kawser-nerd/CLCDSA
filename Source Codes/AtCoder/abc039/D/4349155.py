H,W=map(int,input().split())
S=[list(input()) for i in range(H)]
T=[["" for j in range(W)] for i in range(H)]
dy=[1,1,1,0,-1,-1,-1,0]
dx=[1,0,-1,-1,-1,0,1,1]
for i in range(H):
    for j in range(W):
        flag=1
        for k in range(8):
            ni=i+dx[k]
            nj=j+dy[k]
            if 0<=ni<H and 0<=nj<W:
                if S[ni][nj]==".":
                    flag=0
                    break
        if flag and S[i][j]=="#":
            T[i][j]="#"
        else:
            T[i][j]="."
U=[["." for j in range(W)] for i in range(H)]
for i in range(H):
    for j in range(W):
        if T[i][j]==".":
            continue
        U[i][j]="#"
        for k in range(8):
            ni=i+dx[k]
            nj=j+dy[k]
            if 0<=ni<H and 0<=nj<W:
                U[ni][nj]="#"
flag=1
for i in range(H):
    for j in range(W):
        if S[i][j]!=U[i][j]:
            flag=0
            break
    if flag==0:
        break
if flag:
    print("possible")
    for line in T:
        print("".join(line))
else:
    print("impossible")