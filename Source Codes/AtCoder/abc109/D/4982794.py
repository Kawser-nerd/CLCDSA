H , W = map(int,input().split())
ahw = [list(map(int,input().split())) for _ in range(H)]
ans = []
for i in range(H):
    for j in range(W):
        # ?????????
        if ahw[i][j] & 1:
            # ????????
            if j < W - 1:
                if ahw[i][j+1] & 1:
                    ahw[i][j] -= 1
                    ahw[i][j+1] += 1
                    ans.append([i,j,i,j+1])
        # ?????????
        if ahw[i][j] & 1:
            # ????????
            if i < H - 1:
                if ahw[i+1][j] & 1:
                    ahw[i][j] -= 1
                    ahw[i+1][j] += 1
                    ans.append([i,j,i+1,j])
        if (ahw[i][j] & 1) and (j < W - 1):
            ahw[i][j] -= 1
            ahw[i][j+1] += 1
            ans.append([i,j,i,j+1])
            
        if (ahw[i][j] & 1) and (i < H - 1):
            ahw[i][j] -= 1
            ahw[i+1][j] += 1
            ans.append([i,j,i+1,j])
print(len(ans))
for a in ans:
    print(a[0]+1,a[1]+1,a[2]+1,a[3]+1)