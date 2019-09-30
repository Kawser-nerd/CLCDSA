H, W = map(int, input().split())
f = [list(input()) for _ in range(H)]

for y in range(H):
    for x in range(W):
        if f[y][x] == '#':
            flag = 0
            for dy, dx in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                ny, nx = y + dy, x + dx
                if 0 <= nx < W and 0 <= ny < H:
                    if f[ny][nx] == '#':
                        flag = 1
            if flag == 0:
                print('No')
                exit()
print('Yes')