h, w = map(int, input().split())
s = [list(input()) for _ in range(h)]

t = []
for i in range(h):
    t.append([] + s[i])

for i in range(h):
    for j in range(w):
        if s[i][j] == '.':
            for x in range(max(0, i-1), min(h, i+2)):
                for y in range(max(0, j-1), min(w, j+2)):
                    t[x][y] = '.'

u = []
for i in range(h):
    u.append([] + t[i])

for i in range(h):
    for j in range(w):
        if t[i][j] == '#':
            for x in range(max(0, i-1), min(h, i+2)):
                for y in range(max(0, j-1), min(w, j+2)):
                    u[x][y] = '#'

#print(*s, sep='\n')
#print(*t, sep='\n')
#print(*u, sep='\n')

if s == u:
    print('possible')
    for i in range(h):
        print(''.join(t[i]))
else:
    print('impossible')