H, W = map(int, input().split())
field = [list(input()) for _ in range(H)]

for y in range(H):
    for x in range(W):
        if field[y][x] == '#':
            flag = False
            for dy, dx in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                ny, nx = y + dy, x + dx
                if 0 <= nx < W and 0 <= ny < H:
                    if field[ny][nx] == '#':
                        flag = True
                else:
                    continue
            if flag is False:
                print('No')
                exit()
print('Yes')