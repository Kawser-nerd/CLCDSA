H, W = map(int, input().split())
c = [list(input()) for _ in range(H)]

for y in range(H):
    for x in range(W):
        if c[y][x] == 's':
            sy, sx = y, x
        elif c[y][x] == 'g':
            gy, gx = y, x

q = []
q.append([sy, sx, 2])
crash = [[-1]*W for _ in range(H)]
while q:
    y, x, power = q.pop()
    for dy,dx in [[1,0],[0,1],[-1,0],[0,-1]]:
        ny,nx = dy+y,dx+x
        if 0<= ny < H and 0<= nx < W and c[ny][nx] != '#' and crash[ny][nx] < power:
            if nx == gx and ny == gy:
                print("YES")
                exit()
            q.append([ny, nx, power])
            crash[ny][nx] = power
        elif 0<= ny < H and 0<= nx < W and c[ny][nx] == '#' and crash[ny][nx] < power:
            q.append([ny, nx, power-1])
            crash[ny][nx] = power

print("NO")