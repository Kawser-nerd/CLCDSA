H, W = map(int, input().split())
a = [input() for i in range(H)]
a = [i for i in a if '#' in i]

sharp = []
for i in range(W):
    flg = 0
    for j in range(len(a)):
        if a[j][i] == '#':
            flg = 1
    if flg == 1:
        sharp.append(i)

for i in range(len(a)):
    ans = ''
    for j in sharp:
        ans += a[i][j]
    print(ans)