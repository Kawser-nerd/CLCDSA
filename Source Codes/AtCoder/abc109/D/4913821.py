H,W = list(map(int,input().split()))
a = [list(map(int,input().split())) for i in range(H)]
lis = []
for i in range(H):
    for j in range(W):
        if not i == H-1:
            if (a[i][j]) % 2 == 1:
                a[i+1][j] = a[i+1][j]+1 
                lis.append((i,j,i+1,j))
        else:
            if not j == W-1:
                if (a[i][j]) % 2 == 1:
                    a[i][j+1] = a[i][j+1]+1
                    lis.append((i,j,i,j+1))
print(len(lis))
for i in lis:
    print(i[0]+1,i[1]+1,i[2]+1,i[3]+1)