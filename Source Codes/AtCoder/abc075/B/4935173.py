H, W = [int(i) for i in input().split()]
minelist = [list(input()) for i in range(H)]
dx = [-1, 0 , 1]
dy = [-1, 0 , 1]
for i in range(H):
    for j in range(W):
        count = 0
        if minelist[i][j] == "#":
            continue
        if minelist[i][j] == ".":
            for l in dx:
                for m in dy:
                    if (i + l < 0) or (i + l > H -1 ) or (j + m < 0) or (j + m > W -1):
                        continue
                    if minelist[i + l][j + m] == "#":
                        count += 1
        minelist[i][j] = str(count)
for i in minelist:
    k = "".join(i)
    print(k)