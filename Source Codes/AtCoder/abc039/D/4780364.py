h, w = map(int, input().split())
s = [list(input()) for _ in range(h)]
dx = [-1, 0, 1]
dy = [-1, 0, 1]
a = [[s[i][j] for j in range(w)] for i in range(h)]
for i in range(h):
    for j in range(w):
        if s[i][j] == '.':
            for x in dx:
                for y in dy:
                    if x!=0 or y!=0:
                        nx = i + x
                        ny = j + y
                        if 0<=nx<h and 0<=ny<w:
                            a[nx][ny] = '.'
b = [['.' for j in range(w)] for i in range(h)]
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            for x in dx:
                for y in dy:
                    nx = i + x
                    ny = j + y
                    if 0<=nx<h and 0<=ny<w:
                        b[nx][ny] = '#'
if(b == s):
    print("possible")
    for i in range(h):
        print("".join(a[i]))
else:
    print("impossible")