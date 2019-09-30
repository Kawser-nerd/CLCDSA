N,A,B = map(int,input().split())
M = 2**(N-1)

if N==1:
    print('YES')
    print(A,B)
    exit()

gray = [0]
for i in range(1,M):
    gray.append(gray[-1] ^ (i&(-i)))
grid = [gray, [a+M for a in gray]]

for i,row in enumerate(grid):
    if A in row:
        sx,sy = row.index(A),i
    if B in row:
        gx,gy = row.index(B),i

if (abs(sx-gx) + abs(sy-gy)) % 2:
    print('YES')
else:
    print('NO')
    exit()

ans = [A]

x,y = sx,sy
while (gx-x)%M != 1:
    x += 1
    x %= M
    ans.append(grid[y][x])
y = 1-y
ans.append(grid[y][x])
while x != sx:
    x -= 1
    x %= M
    ans.append(grid[y][x])

if x != gx:
    while 1:
        x -= 1
        x %= M
        ans.append(grid[y][x])
        y = 1-y
        ans.append(grid[y][x])
        if x==gx: break

print(*ans)