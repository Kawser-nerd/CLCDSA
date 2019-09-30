import copy

field = []

for i in range(10):
    field.append(list(input()))

field2 = copy.deepcopy(field)
dx = [1, 0, -1,  0]
dy = [0, 1,  0, -1]

def dfs(x,y):
    field2[x][y] = 'x'
    for i in range(4):
        if 0<= x+dx[i] <=9 and 0<= y+dy[i] <=9 and field2[x+dx[i]][y+dy[i]]=='o':
            dfs(x+dx[i], y+dy[i])

def check(field2):
    for i in range(10):
        for j in range(10):
            if field2[i][j] == 'o':
                return False
    return True

for i in range(10):
    for j in range(10):
        field2 = copy.deepcopy(field)
        dfs(i,j)

        if check(field2) == True:
            print("YES")
            exit()

print("NO")