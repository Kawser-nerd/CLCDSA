sx, sy, tx, ty = map(int, input().split())

s = ''
dx = tx - sx
dy = ty - sy
for i in range(dx):
    s += 'R'

for i in range(dy):
    s += 'U'

for i in range(dx):
    s += 'L'

for i in range(dy+1):
    s += 'D'

for i in range(dx+1):
    s += 'R'

for i in range(dy+1):
    s += 'U'

s += 'LU'

for i in range(dx+1):
    s += 'L'

for i in range(dy+1):
    s += 'D'

s += 'R'

print(s)