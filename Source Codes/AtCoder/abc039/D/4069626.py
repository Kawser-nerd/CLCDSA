H, W = map(int, input().split())
G = [list(input()) for i in range(H)]
ans = [['#'] * W for i in range(H)]

# ???
for h in range(H):
    for w in range(W):
        if G[h][w] == '.':
            for i in range(-1, 2):
                for j in range(-1, 2):
                    if (0 <= h + i < H) and (0 <= w + j < W):
                        ans[h + i][w + j] = '.'


# ??????????OK
check = [['.'] * W for i in range(H)]
for h in range(H):
    for w in range(W):
        if ans[h][w] == '#':
            for i in range(-1, 2):
                for j in range(-1, 2):
                    if (0 <= h + i < H) and (0 <= w + j < W):
                        check[h + i][w + j] = '#'

if G == check:
    print('possible')
    for row in ans:
        print(''.join(row))
else:
    print('impossible')