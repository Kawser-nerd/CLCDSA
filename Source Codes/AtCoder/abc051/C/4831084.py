sx, sy, tx, ty = map(int, input().split())

s = ''
dx = tx - sx
dy = ty - sy

s += 'R'*dx + 'U'*dy + 'L'*dx + 'D'*(dy+1)
s += 'R'*(dx+1) + 'U'*(dy+1) + 'LU' + 'L'*(dx+1) + 'D'*(dy+1) + 'R'

print(s)