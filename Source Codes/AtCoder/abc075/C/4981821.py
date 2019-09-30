n, m = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(m)]

ad = [[0]*n for i in range(n)]

for x in ab:
    ad[x[0]-1][x[1]-1] = 1
    ad[x[1]-1][x[0]-1] = 1

nodes = [0]*n
ans = 0
flag = True
while flag:
    flag = False
    for i in range(n):
        if nodes[i] == 0 and sum(ad[i]) == 1:
            ans +=1
            nodes[i] = 1
            flag = True
            for j in range(n):
                if ad[i][j] == 1:
                    ad[j][i] =0
print(ans)