r,c, d = map(int,input().split())

maze = []
for i in range(r):
    onelist = list(map(int,input().split()))
    maze.append(onelist)
    
ma = 1
for i in range(r):
    for j in range(c):
        if (i + j) % 2 == d % 2 and ma <= maze[i][j] and i + j <= d:
            ma = maze[i][j]
        else:
            None
print(ma)