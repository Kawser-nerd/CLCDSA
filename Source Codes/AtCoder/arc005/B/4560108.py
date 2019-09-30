def f(i):
    if i < 0:
        return -i
    elif i > 8:
        return 16 - i
    else:
        return i

x, y, W = input().split()
x, y = int(x)-1, int(y)-1
css = [input() for _ in range(9)]

if 'R' in W:
    dx = 1
elif 'L' in W:
    dx = -1
else:
    dx = 0

if 'D' in W:
    dy = 1
elif 'U' in W:
    dy = -1
else:
    dy = 0

poss = []
for t in range(4):
    poss.append((x+dx*t, y+dy*t))

anss = ''
for x, y in poss:
    anss += css[f(y)][f(x)]
print(anss)