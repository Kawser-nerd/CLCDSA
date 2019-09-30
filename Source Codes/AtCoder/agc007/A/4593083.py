def chk(r, c):
    cnt_in, cnt_out = 0, 0
    if (r, c) == (0, 0): cnt_in += 1
    if (r, c) == (H - 1, W - 1): cnt_out += 1
    if r - 1 >= 0:
        if a[r - 1][c] == '#': cnt_in += 1
    if r + 1 < H:
        if a[r + 1][c] == '#': cnt_out += 1
    if c - 1 >= 0:
        if a[r][c - 1] == '#': cnt_in += 1
    if c + 1 < W:
        if a[r][c + 1] == '#': cnt_out += 1
    return cnt_in == 1 and cnt_out == 1


H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

bl = True
for r in range(H):
    for c in range(W):
        if a[r][c] == '#':
            if not chk(r, c):
                bl = False
                break
    else:
        continue
    break

print('Possible' if bl else 'Impossible')