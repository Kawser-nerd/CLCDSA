H,W=map(int,input().split())
 
M=[[c%2==1 for c in map(int,input().split())] for i in range(H)]
 
LIST=[]
 
for i in range(H):
    for j in range(W):
        if M[i][j]:
            if j < W-1:
                LIST.append((i+1,j+1,i+1,j+2))
                M[i][j+1] ^= True
            elif i < H-1:
                LIST.append((i+1,j+1,i+2,j+1))
                M[i+1][j] ^= True
                
print(len(LIST))
 
for c in LIST:
    print(*c)