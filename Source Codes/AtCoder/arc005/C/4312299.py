H, W = map(int, input().split())
c = [list(input()) for _ in range(H)]
d = [[9] * W for _ in range(H)]
for i in range(H):
    for j in range(W):
        if c[i][j] == 's':
            q = [(i, j, 0)]
        if c[i][j] == 'g':
            gi = i
            gj = j
while len(q) > 0:
    i, j, k = q.pop()
    if i < 0 or i >= H or j < 0 or j >= W:
        continue
    if c[i][j] == '#':
        k += 1
    if k > 2:
        continue
    if c[i][j] == 'g':
        print('YES')
        break
    if d[i][j] <= k:
        continue
    d[i][j] = k
    q.append((i - 1, j, k))
    q.append((i + 1, j, k))
    q.append((i, j - 1, k))
    q.append((i, j + 1, k))
else:
    print('NO')