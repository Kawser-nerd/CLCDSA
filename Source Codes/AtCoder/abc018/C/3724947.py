from collections import deque

R, C, K = map(int, input().split())
inputs =[list(input()) for _ in range(R)]

que = deque()
result = 0

# ???(x)????????
for r in range(R):
    for c in range(C):
        if inputs[r][c] == 'x':
            que.append((r, c))

for k in range(K-1):
    tmp_que = deque()
    while que:
        # ???(x)???
        r, c = que.pop()
        # ????????????????
        for i, j in [(r+1, c), (r-1, c), (r, c-1), (r, c+1)]:
            if 0 <= i < R and 0 <= j < C and inputs[i][j] == 'o':
                inputs[i][j] = 'x'
                tmp_que.append((i, j))
    que = tmp_que

for x in range(K-1, R-K+1):
    for y in range(K-1, C-K+1):
        if inputs[x][y] == 'o':
            result += 1

print(result)