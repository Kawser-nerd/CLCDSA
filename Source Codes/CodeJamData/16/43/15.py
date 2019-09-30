import sys
sys.setrecursionlimit(1000000000)

INF = 1000000000
order = {}
order['gauche'] = ['bas', 'haut']
order['bas'] = ['droite', 'gauche']
order['droite'] = ['haut', 'bas']
order['haut'] = ['gauche', 'droite']
vector = {}
vector['gauche'] = (0, -1)
vector['bas'] = (1, 0)
vector['droite'] = (0, 1)
vector['haut'] = (-1, 0)

def pp(s):
    s = str(s)
    sys.stderr.write(s + '\n')
    sys.stderr.flush()

T = int(input())
for N in range(1, T + 1):
    out = 'Case #' + str(N) + ':\n'

    n, m = map(int, input().split())
    g = [[' ' for _ in range(m)] for _ in range(n)]
    pos = [(0, 0, '') for _ in range(2 * (n + m))]
    arr = [(0, 0) for _ in range(2 * (n + m))]
    for j in range(m):
        pos[j] = (0, j, 'bas')
        arr[j] = (-1, j,)
        pos[n + m + j] = (n - 1, m - 1 - j, 'haut')
        arr[n + m + j] = (n, m - 1 - j,)
    for i in range(n):
        pos[m + i] = (i, m - 1, 'gauche')
        arr[m + i] = (i, m,)
        pos[n + 2 * m + i] = (n - 1 - i, 0, 'droite')
        arr[n + 2 * m + i] = (n - 1 - i, -1,)
        
    k = 2 * (n + m)
    love = [0 for _ in range(k)]
    t = [int(i) for i in input().split()]
    for i in range(k // 2):
        x = t[2 * i] - 1
        y = t[2 * i + 1] - 1
        love[x], love[y] = y, x
      
    left = {}
    for i in range(k):
        left[i] = True
    ins = [{} for _ in range(k)]
    for x in range(k):
        y = love[x]
        if x < y:
            for z in range(x + 1, y):
                ins[x][z] = True
        else:
            for z in range(x + 1, k):
                ins[x][z] = True
            for z in range(y):
                ins[x][z] = True
                

    
    done = False
    impossible = False
    while not done:
        # pp('# ' + str(len(left)))
        ou = ''
        for i in range(n):
            for j in range(m):
                if g[i][j] != ' ':
                    ou += g[i][j]
                else:
                    ou += '.'
            if i != n - 1:
                ou += '\n'
        # pp(ou)
        # for i in left:
            # pp(str(i) + ' ' + str(ins[i]))
        if len(left) == 0:
            done = True
            break
        found = False
        lefti = [i for i in left]
        lefti.sort()
        for i in lefti:
            if found:
                break
            if len(ins[i]) == 0:
                found = True
                x, y, dir = pos[i]
                lx, ly = arr[love[i]]
                nb = 0
                while x != lx or y != ly:
                    # pp('--> ' + str(x) + ' ' + str(y))
                    nb += 1
                    if nb >= 2 * n * m + 5:
                        impossible = True
                        break
                    if not (0 <= x < n and 0 <= y < m):
                        impossible = True
                        break
                    if g[x][y] == '\\':
                        if dir == 'haut':
                            vx, vy = vector['gauche']
                            x += vx
                            y += vy
                            dir = 'gauche'
                        elif dir == 'droite':
                            vx, vy = vector['bas']
                            x += vx
                            y += vy
                            dir = 'bas'
                        elif dir == 'bas':
                            vx, vy = vector['droite']
                            x += vx
                            y += vy
                            dir = 'droite'
                        elif dir == 'gauche':
                            vx, vy = vector['haut']
                            x += vx
                            y += vy
                            dir = 'haut'
                    elif g[x][y] == '/':
                        if dir == 'haut':
                            vx, vy = vector['droite']
                            x += vx
                            y += vy
                            dir = 'droite'
                        elif dir == 'droite':
                            vx, vy = vector['haut']
                            x += vx
                            y += vy
                            dir = 'haut'
                        elif dir == 'bas':
                            vx, vy = vector['gauche']
                            x += vx
                            y += vy
                            dir = 'gauche'
                        elif dir == 'gauche':
                            vx, vy = vector['bas']
                            x += vx
                            y += vy
                            dir = 'bas'
                    elif g[x][y] == ' ':
                        ndir = order[dir][0]
                        vx, vy = vector[ndir]
                        if dir in ['haut', 'bas']:
                            g[x][y] = '\\'
                        else:
                            g[x][y] = '/'
                        x += vx
                        y += vy
                        dir = ndir
                j = love[i]
                del left[i]
                del left[j]
                for x in left:
                    if i in ins[x]:
                        del ins[x][i]
                    if j in ins[x]:
                        del ins[x][j]
        if not found:
            break

    if done and not impossible:
        for i in range(n):
            for j in range(m):
                if g[i][j] != ' ':
                    out += g[i][j]
                else:
                    out += '/'
            if i != n - 1:
                out += '\n'
    else:
        out += 'IMPOSSIBLE'
            
    out += '\n'
    sys.stdout.write(out)
    sys.stdout.flush()
    sys.stderr.write(out)
    sys.stderr.flush()