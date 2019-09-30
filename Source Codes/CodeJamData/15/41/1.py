from sys import stdin

def getInt():
    return int(stdin.readline())

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

def exists(z):
    for k in z:
        return True
    return False

numCases = getInt()
for case in xrange(1, 1+numCases):
    (R, C) = getInts()
    grid = [stdin.readline().strip() for i in xrange(R)]
    ldots = [min([j for j in xrange(C) if grid[i][j] != "."]+[C]) for i in xrange(R)]
    rdots = [max([j for j in xrange(C) if grid[i][j] != "."]+[-1]) for i in xrange(R)]
    udots = [min([i for i in xrange(R) if grid[i][j] != "."]+[R]) for j in xrange(C)]
    ddots = [max([i for i in xrange(R) if grid[i][j] != "."]+[-1]) for j in xrange(C)]
    ans = 0
    impossible = False
    for i in xrange(R):
        if impossible:
            break
        for j in xrange(C):
            if grid[i][j] == ".":
                pass
            else:
                canLeft = ldots[i] < j
                canRight = rdots[i] > j
                canUp = udots[j] < i
                canDown = ddots[j] > i
                if not (canLeft or canRight or canUp or canDown):
                    impossible = True
                    break
                if (canLeft and grid[i][j] == "<") or (canRight and grid[i][j] == ">") or (canUp and grid[i][j] == "^") or (canDown and grid[i][j] == "v"):
                    pass
                else:
                    ans += 1
    if impossible:
        print "Case #%d: IMPOSSIBLE" % case
    else:
        print "Case #%d: %d" % (case, ans)
