#!/usr/bin/env python

fin = open("3.in", "r")
fout = open("3.out", "w")

def check_l(G, x, y):
    if y == 0:
        return set()
    y -= 1
    if G[x][y] == '#':
        return set()
    elif G[x][y] == '.':
        n = check_l(G, x, y)
        if n == None:
            return None
        return set([(x, y)]) | n
    elif G[x][y] == '|' or G[x][y] == '-':
        return None
    elif G[x][y] == '\\':
        return check_u(G, x, y)
    elif G[x][y] == '/':
        return check_d(G, x, y)

def check_r(G, x, y):
    if y == len(G[0]) - 1:
        return set()
    y += 1
    if G[x][y] == '#':
        return set()
    elif G[x][y] == '.':
        n = check_r(G, x, y)
        if n == None:
            return None
        return set([(x, y)]) | n
    elif G[x][y] == '|' or G[x][y] == '-':
        return None
    elif G[x][y] == '\\':
        return check_d(G, x, y)
    elif G[x][y] == '/':
        return check_u(G, x, y)

def check_u(G, x, y):
    if x == 0:
        return set()
    x -= 1
    if G[x][y] == '#':
        return set()
    elif G[x][y] == '.':
        n = check_u(G, x, y)
        if n == None:
            return None
        return set([(x, y)]) | n
    elif G[x][y] == '|' or G[x][y] == '-':
        return None
    elif G[x][y] == '\\':
        return check_l(G, x, y)
    elif G[x][y] == '/':
        return check_r(G, x, y)

def check_d(G, x, y):
    if x == len(G) - 1:
        return set()
    x += 1
    if G[x][y] == '#':
        return set()
    elif G[x][y] == '.':
        n = check_d(G, x, y)
        if n == None:
            return None
        return set([(x, y)]) | n
    elif G[x][y] == '|' or G[x][y] == '-':
        return None
    elif G[x][y] == '\\':
        return check_r(G, x, y)
    elif G[x][y] == '/':
        return check_l(G, x, y)

def try_set(l, want):
    if l == []:
        if len(want) == 0:
            return []
        else:
            return None

    a = try_set(l[1:], want - l[0][0])
    if a != None:
        a.append('-')
        return a

    a = try_set(l[1:], want - l[0][1])
    if a != None:
        a.append('|')
        return a

    return None

T = int(fin.readline())
for t in range(T):
    print str(t+1)
    R, C = map(int, fin.readline().split())
    grid = []
    for r in range(R):
        grid.append(list(fin.readline().strip()))
    beams = [[[None, None] for y in range(C)] for x in range(R)]
    poss = True
    for x in range(R):
        for y in range(C):
            if grid[x][y] == '|' or grid[x][y] == '-':
                l = check_l(grid, x, y)
                r = check_r(grid, x, y)
                u = check_u(grid, x, y)
                d = check_d(grid, x, y)
                if l != None and r != None:
                    beams[x][y][0] = l | r
                if u != None and d != None:
                    beams[x][y][1] = u | d
                if beams[x][y] == [None, None]:
                    poss = False

    if not poss:
        ans = "IMPOSSIBLE"
        fout.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
        continue

    free = {}
    for x in range(R):
        for y in range(C):
            if grid[x][y] == '|' or grid[x][y] == '-':
                if beams[x][y] == [None, None]:
                    continue
                elif beams[x][y][0] == None:
                    grid[x][y] = '|'
                    for (x1, y1) in beams[x][y][1]:
                        grid[x1][y1] = 'T'
                    beams[x][y] = [None, None]
                elif beams[x][y][1] == None:
                    grid[x][y] = '-'
                    for (x1, y1) in beams[x][y][0]:
                        grid[x1][y1] = 'T'
                    beams[x][y] = [None, None]
                elif beams[x][y][0] | beams[x][y][1] == beams[x][y][0]:
                    grid[x][y] = '-'
                    for (x1, y1) in beams[x][y][0]:
                        grid[x1][y1] = 'T'
                    beams[x][y] = [None, None]
                elif beams[x][y][0] | beams[x][y][1] == beams[x][y][1]:
                    grid[x][y] = '|'
                    for (x1, y1) in beams[x][y][1]:
                        grid[x1][y1] = 'T'
                    beams[x][y] = [None, None]
                else:
                    free[(x, y)] = beams[x][y]

    empty = {}
    for (x, y) in free.keys():
        for el in free[(x, y)][0] | free[(x, y)][1]:
            (x1, y1) = el
            if grid[x1][y1] == 'T':
                continue
            if (x1, y1) not in empty:
                empty[(x1, y1)] = []
            empty[(x1, y1)].append((x, y))

    for x in range(R):
        for y in range(C):
            if grid[x][y] == '.' and (x, y) not in empty:
                poss = False

    if not poss:
        ans = "IMPOSSIBLE"
        fout.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
        continue

    all_empty = set(empty.keys())
    all_free = free.keys()
    free_choices = [free[f] for f in all_free]
    settings = try_set(free_choices, all_empty)

    if settings == None:
        ans = "IMPOSSIBLE"
        fout.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
        continue

    settings.reverse()
    for i in range(len(settings)):
        (x, y) = all_free[i]
        s = settings[i]
        grid[x][y] = s

    for x in range(R):
        for y in range(C):
            if grid[x][y] == 'T':
                grid[x][y] = '.'

    fout.write("Case #" + str(t+1) + ": " + "POSSIBLE" + "\n")
    for r in range(R):
        fout.write(''.join(grid[r]) + "\n")
