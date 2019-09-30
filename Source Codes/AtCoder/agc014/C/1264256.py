import collections
h,w,k = map(int, input().split())
a = [[c for c in input()] for i in range(h)]

min_dis  = w*h
s = False
for i in range(h):
    for j in range(w):
        if a[i][j] == 'S':
            s = (i, j)
            break
    if s:
        break

dq = collections.deque()
dq.append((0, s[0], s[1]))

moved = [[False for j in range(w)] for i in range(h)]
while dq:
    m, y, x = dq.popleft()
    if moved[y][x]:
        continue
    else:
        moved[y][x] = True
    if m > k:
        continue
    if y == 0 or y == h-1 or x == 0 or x == w-1:
        print(1)
        exit()
    min_dis = min(min_dis, y, h-1-y, x, w-1-x)
    for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        if 0<=y+dy<h and 0<=x+dx<w and a[y+dy][x+dx] == '.' and not moved[y+dy][x+dx]:
            dq.append((m+1, y+dy, x+dx))
print(1+(min_dis+k-1)//k)