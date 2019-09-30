a,b = map(int,input().split()) #??
grid = []
for i in range(50):
    whiteline = ["." for k in range(100)]
    grid.append(whiteline)
for i in range(50):
    blackline = ["#" for k in range(100)]
    grid.append(blackline)

b += -1
check = 1
x = 1
y = 1
while b > 0:
    grid[y][x] = "#"
    b += -1
    if x+2 < 50:
        x += 2
    else:
        check = check * (-1)
        if check == 1:
            x = 2
        else:
            x = 1
        y += 2

a += -1
check = 1
x = 1
y = 55
while a > 0:
    grid[y][x] = "."
    a += -1
    if x+2 < 50:
        x += 2
    else:
        check = check * (-1)
        if check == 1:
            x = 2
        else:
            x = 1
        y += 2

print(100,100)
for i in range(100):
    for k in range(100):
        if k != 99:
            print(grid[i][k],end = "")
        else:
            print(grid[i][k])