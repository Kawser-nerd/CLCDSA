x, y, W = [i for i in input().split()]
x = int(x) -1
y = int(y) -1
 
 
a = [input() for _ in range(9)]
 
dx = 1 if 'R' in W else -1 if 'L' in W else 0
dy = 1 if 'D' in W else -1 if 'U' in W else 0
 
ans = ''
 
ans = ans + a[y][x]
 
for i in range(3):
    if x + dx == 9:
        dx = -1
        x = 7
    elif x + dx == -1:
        dx = 1
        x = 1
    else:
        x = x + dx
 
    if y + dy == 9:
        dy = -1
        y = 7
    elif y + dy == -1:
        dy = 1
        y = 1
    else:
        y = y + dy
 
    ans = ans + a[y][x]
 
 
print(ans)