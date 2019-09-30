x, y, W = input().split()
T = [[] for i in range(10)]
d = {'R':(0, 1), 'L': (0, -1), 'D': (1, 0), 'U':(-1, 0), 'RD': (1, 1), 'RU': (-1, 1), 'LD': (1, -1), 'LU': (-1, -1)}
rev = {'R': 'L', 'L':'R', 'U':'D', 'D':'U', 'RU':'LD',
       'LD': 'RU', 'LU': 'RD', 'RD': 'LU'}
rev1 = {'LD': 'RD', 'RD': 'LD', 'LU': 'RU', 'RU': 'LU'}
rev2 = {'LU': 'LD', 'LD': 'LU', 'RU': 'RD', 'RD': 'RU'}
for i in range(9):
    T[i] = list(input())
t = ''
x, y = int(x) - 1, int(y) - 1
y, x = x, y
t += T[x][y]
for i in range(3):
    nx, ny = x + d[W][0], y + d[W][1]
    if not (0 <= nx < 9 and 0 <= ny < 9):
        if W in ['R', 'L', 'D', 'U']:
            W = rev[W]
            nx, ny = x + d[W][0], y + d[W][1]
        else:
            if (not 0 <= nx < 9) and (not 0 <= ny < 9):
                W = rev[W]
                nx, ny = x + d[W][0], y + d[W][1]
            else:
                if not 0 <= nx < 9:
                    W = rev2[W]
                    nx, ny = x + d[W][0], y + d[W][1]
                else:
                    W = rev1[W]
                    nx, ny = x + d[W][0], y + d[W][1]
    t += T[nx][ny]
    x, y = nx, ny

print(t)