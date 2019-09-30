
input = raw_input

def walk_set(maze, pos1, pos2, dir):
    newpos = (pos1[0] + dir[0], pos1[1] + dir[1])
    if newpos == pos2:
        return True
    if not (0 <= newpos[0] < len(maze) and 0 <= newpos[1] < len(maze[0])):
        return False
    c = maze[newpos[0]][newpos[1]]
    if c == "/":
        newdir = (-dir[1], -dir[0])
    elif c == "\\":
        newdir = (dir[1], dir[0])
    else:
        newdir = (-dir[1], dir[0])
        if dir[0] == 0:
            nc = "/"
        else:
            nc = "\\"
        maze[newpos[0]][newpos[1]] = nc
    #print(newpos)
    return walk_set(maze, newpos, pos2, newdir)

def solve(r, c, l):
    #ll = [(i, u) for (i, u) in enumerate(l)]
    ll = [None] * len(l)
    for i in range(0, len(l), 2):
        u, v = l[i], l[i + 1]
        ll[u - 1] = (u - 1, v - 1)
        ll[v - 1] = (v - 1, u - 1)
    maze = [[" " for i in range(c)] for j in range(r)]
    def pos(i):
        if i < c:
            return (-1, i)
        elif i < r + c:
            return (i - c, c)
        elif i < c + r + c:
            return (r, c + r + c - i - 1)
        else:
            return (r + c + r + c - 1 - i, -1)
    def dir(i):
        if i < c:
            return (1, 0)
        elif i < r + c:
            return (0, -1)
        elif i < c + r + c:
            return (-1, 0)
        else:
            return (0, 1)
    while ll != []:
        w = None
        for j in range(len(ll)):
            nj = (j + 1) % len(ll)
            a, b = ll[j]
            if ll[nj] == (b, a):
                w = a, b
                break
        else:
            return None
        a, b = w
        ll.remove((a, b))
        ll.remove((b, a))
        #print(pos(a), dir(a), a, r, c, maze, pos(b), ll)
        if not walk_set(maze, pos(a), pos(b), dir(a)):
            return None
    for i in range(r):
        for j in range(c):
            if maze[i][j] == " ":
                maze[i][j] = "/"
    return maze

t = int(input())
for i in range(t):
    print "Case #%d:" % (i + 1)
    r, c = map(int, input().split())
    l = map(int, input().split())
    sl = solve(r, c, l)
    if sl == None:
        print "IMPOSSIBLE"
        continue
    print "\n".join("".join(u) for u in sl)
    
