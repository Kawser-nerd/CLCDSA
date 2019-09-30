H,W = list(map(int,input().split()))
a = [list(map(int,input().split())) for _ in range(H)]

out = []
for i in range(H):
    for j in range(W-1):
        if a[i][j]%2:
            out.append([i+1,j+1,i+1,j+2])
            a[i][j] -=1
            a[i][j+1] +=1
for i in range(H-1):
    if a[i][-1]%2:
        out.append([i+1,W,i+2,W])
        a[i][W-1] -=1
        a[i+1][W-1] += 1

print(len(out))
for sub in out:
    print(" ".join(map(str,sub)))