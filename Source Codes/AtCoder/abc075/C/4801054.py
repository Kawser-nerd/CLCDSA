N , M = map(int,input().split()) 
ab = [list(map(int,input().split())) for _ in range(M)]
flg = True
ch = [0] * N
gl = [[0] * N for _ in range(N)] 
# ?????????
for x in ab:
    gl[x[0]-1][x[1]-1] = 1
    gl[x[1]-1][x[0]-1] = 1
# ???????????????????
# ?????????????????????????????
# ??????????????????????????????
count = 0
while flg:
    flg = False
    for i in range(N):
        if (ch[i] == 0 )and (sum(gl[i]) == 1):
            ch[i] = 1
            count += 1
            flg = True
            for j in range(N):
                if gl[i][j] == 1:
                    gl[j][i] = 0
print(count)