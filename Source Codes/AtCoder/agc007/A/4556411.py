h, w = map(int, input().split())
A = [input() for i in range(h)]
cnt = 0
for i in range(h):
    for j in range(w):
        if A[i][j] == '#':
            cnt += 1
if cnt == w + h - 1:
    print('Possible')
else:
    print('Impossible')