s = input().split('T')
x, y = map(int, input().split())
s = [len(_) for _ in s]
dx = s[::2]
dy = s[1::2]

x = abs(x-dx[0])
y = abs(y)
dx = dx[1:]
px = 0
py = 0
for d in reversed(sorted(dx)) :
    if px > x :
        px -= d
    else :
        px += d

for d in reversed(sorted(dy)) :
    if py > y :
        py -= d
    else :
        py += d

if px == x and py == y :
    print('Yes')
else :
    print('No')