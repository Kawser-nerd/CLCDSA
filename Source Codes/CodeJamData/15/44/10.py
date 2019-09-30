cnt = 0
dirs = ((-1, 0), (0, -1), (0, 1), (1, 0))
fff = []

def correct(d):
    n, m = len(d), len(d[0])
    for x, row in enumerate(d):
        for y, cell in enumerate(d[x]):
            if d[x][y] == 0: continue
            sas = [d[x+dx][(y+dy)%m] for dx, dy in dirs if 0 <= x+dx < n]
            a = d[x][y]
            if sas.count(a) > a or sas.count(a) + sas.count(0) < a: return False
    return True

def dfs(d, x, y):
    global cnt
    if x == len(d):
        if correct(d):
            cnt += 1
            fff.append([t[:] for t in d])
        return
    for a in (1, 2, 3): #pos(d, x, y):
        d[x][y] = a
        if not correct(d): continue
        if y < len(d[0])-1:
            dfs(d, x, y+1)
        else:
            dfs(d, x+1, 0)
    d[x][y] = 0

def equal(a, b):
    for i in xrange(len(a[0])):
        c = [t[i:] + t[:i] for t in a]
        if all(c[x][y] == b[x][y] for x in xrange(len(a)) for y in xrange(len(a[0]))): return True
    return False

for r in xrange(2, 7):
    for c in xrange(3, 7):
        d = [[0]*c for _ in xrange(r)]
        cnt = 0
        fff = []
        dfs(d, 0, 0)
        rrr = []
        for a in fff:
            if all(not equal(a, b) for b in rrr):
                rrr.append(a)
        print '(%d, %d): %d,' % (r, c, len(rrr))
