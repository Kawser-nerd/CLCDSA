H, W = [int(i) for i in input().split()]
list = [list(input()) for i in range(H)]
dxy = [(-1,0), (1, 0), (0, 1), (0, -1)]
flg = True
for i in range(H):
    for j in range(W):
        count = 0
        if list[i][j] == ".":
            continue
        if list[i][j] == "#":
            for l, m in dxy:
                if (i + l < 0) or (i + l > H -1) or (j + m < 0) or (j + m > W -1):
                    continue
                if list[i + l][j + m] == "#":
                    count += 1
        if count == 0:
            flg = False
if flg:
    print("Yes")
else:
    print("No")