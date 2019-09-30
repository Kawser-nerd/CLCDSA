n, a, b = map(int, input().split())
if n == 2:
    win = 'Borys'
else:
    if abs(a - b) % 2 == 0:
        win = 'Alice'
    else:
        win = 'Borys'

print(win)