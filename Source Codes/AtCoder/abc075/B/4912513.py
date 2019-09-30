from sys import exit
H,W = [int(n) for n in input().split()]
S = [0]*H
dxy = [[1,0],[0,1],[0,-1],[-1,0],[1,1],[1,-1],[-1,1],[-1,-1]]
for i in range(H):
    S[i] = list(str(input()))

for i in range(H):
    for j in range(W):
        if S[i][j] == ".":
            cnt = 0
            for d in dxy:
                if(0<= i+d[0] < H and 0<= j+d[1] < W and S[i+d[0]][j+d[1]] == "#"):
                    cnt+=1
            S[i][j] = cnt

for i in range(H):
    for j in range(W):
        print(S[i][j],end="")
    print()