H, W = map(int, input().split())
s = [input() for i in range(H)]
flag = True
for i in range(H):
    for j in range(W):
        if s[i][j] == '#':
            c = 0
            if j > 0:
                if s[i][j - 1] == '#':
                    c += 1
            if j < W - 1:
                if s[i][j + 1] == '#':
                    c += 1
            if i > 0:
                if s[i - 1][j] == '#':
                    c += 1
            if i < H - 1:
                if s[i + 1][j] == '#':
                    c += 1
            if c < 1:
                flag = False
                break
if flag:
    print('Yes')
else:
    print('No')