h, w = map(int, input().split())
sx, sy= map(int, input().split())
gx, gy = map(int, input().split())
c = [list(input()) for _ in range(h)]

sx -= 1
sy -= 1
gx -= 1
gy -= 1

ans = 0
temp = [[sx, sy]]
c[sx][sy] = '#'

while 1:
    #print(temp)
    next = []
    for x, y in temp:
        if x == gx and y == gy:
            print(ans)
            exit()
        if c[x+1][y] == '.':
            c[x+1][y] = '#'
            next.append([x+1, y])
        if c[x-1][y] == '.':
            c[x-1][y] = '#'
            next.append([x-1, y])
        if c[x][y+1] == '.':
            c[x][y+1] = '#'
            next.append([x, y+1])
        if c[x][y-1] == '.':
            c[x][y-1] = '#'
            next.append([x, y-1])
    ans += 1
    temp = [] + next