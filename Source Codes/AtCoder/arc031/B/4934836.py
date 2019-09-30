import sys
sys.setrecursionlimit(100000)
ans_flag = 0
field = [input() for x in range(10)]
field_u = [[1 if field[y][x] == 'x'  else 0 for x in range(10)]for y in range(10)]#x==1 o==0
reached = [[0 for x in range(10)] for y in range(10)]
flag = 0
def dfs(x,y):
    global flag,reached
    if x >= 10 or y >= 10 or x < 0 or y < 0:
        return 
    if field_u[x][y] == 1:
            return 
    if reached[x][y] == 1:
        return
    reached[x][y] = 1
    dfs(x+1,y)
    dfs(x-1,y)
    dfs(x,y+1)
    dfs(x,y-1)
counter = 1
for y in range(10):
    for x in range(10):
        if field[y][x] == 'o':
            counter += 1
            first = [y,x]
for y in range(10):
    for x in range(10):
        if field_u[y][x] == 1:
           # print('ababa')
            field_u[y][x] = 0
            dfs(first[0],first[1])
            ans = [sum(i) for i in reached]
           # print(ans)
            ans = sum(ans)
           # print(counter,ans)
            if counter == ans:
                ans_flag = 1
            reached = [[0 for x in range(10)] for y in range(10)]
            field_u[y][x] = 1


if ans_flag == 1:
    print('YES')
else:
    print('NO')