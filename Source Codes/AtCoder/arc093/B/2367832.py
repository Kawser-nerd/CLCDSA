white, black = map(int,input().split())
white -= 1
black -= 1

grid = [['#' for i in range(100)] for j in range(100)]
for i in range(1, 99):
    for j in range(50, 99):
        grid[i][j] = "."

a = 3
b = 3
while True:
    if white == 0:
        break
    grid[a][b] = "."
    white -= 1
    a += 2
    if a > 93:
        a = 3
        b += 2
    
 
c = 3
d = 53
while True:
    if black == 0:
        break
    grid[c][d] = "#"
    black -= 1
    c += 2
    if c > 93:
        c = 3
        d += 2
    

print(100, 100)
for i in grid:
    print("".join(i))