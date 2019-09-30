n,m = map(int, input().split())

# ??????1
connect = [[0 for i in range(n)] for j in range(n)]

for i in range(m):
    u,v = map(int, input().split())
    connect[u-1][v-1] = 1
    connect[v-1][u-1] = 1


visited = []
stack = []
ans = 0
# ??????
for i in range(n):
    # ?????
    if i not in visited:
        visited.append(i)
        stack.append(i)
        flag = True
        while stack:
            p = stack.pop()
            # ?????????????????????? = ????
            for j in range(n):
                if connect[p][j] == 1:
                    connect[p][j] = 0
                    connect[j][p] = 0
                    stack.append(j)
                    if j not in visited:
                        visited.append(j)
                    else:
                        flag = False
        if flag:
            ans += 1

print(ans)