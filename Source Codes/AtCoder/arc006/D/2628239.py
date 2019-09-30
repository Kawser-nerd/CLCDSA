from collections import deque
h, w = map(int, input().strip().split())
c = []
dx = [0, 0, 1, 1, 1, -1, -1, -1]
dy = [-1, 1, -1, 0, 1, -1, 0, 1]
max_scale = min(h, w) // 7
for _ in range(h):
    cc = input().strip()
    c.append(list(cc))

def inside(y, x):
    return 0 <= y < h and 0 <= x < w

def erase(q, c):
    cnt = 0
    while q:
        qq = q.popleft()
        y = qq[0]
        x = qq[1]

        if not inside(y, x): continue
        if c[y][x] == '.':
            continue
        c[y][x] = '.'
        cnt += 1
        for i in range(len(dx)):
            q.append((y+dy[i], x+dx[i]))
            # cnt += erase(y+dy[i], x+dx[i], c)
    return cnt

def clasify(cnt):
    while cnt > 9 and cnt % 9 == 0:
        cnt //= 9
    while cnt > 121 and cnt % 121 == 0:
        cnt //= 121
    if cnt % 3 == 0:
        return 0
    if cnt % 11 == 0:
        return 2
    return 1

abc = [0] * 3
for y in range(0, h, 3):
    for x in range(w):
        q = deque()
        q.append((y, x))
        cnt = erase(q, c)
        if cnt == 0: continue
        abc[clasify(cnt)] += 1

print(abc[0], abc[1], abc[2])