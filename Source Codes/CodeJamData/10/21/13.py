import sys

def make_dir(path):
    global dirs
    c = 0
    sdir = '/'
    cur = dirs[sdir]
    for s in path[1:]:
        sdir = sdir + s
        if s not in cur:
            cur.add(s)
            dirs[sdir] = set()
            c += 1
        cur = dirs[sdir]
    return c
        
t = int(sys.stdin.readline())
for _ in range(1,t+1):
    dirs = dict()
    dirs['/'] = set()
    n,m = map(int,sys.stdin.readline().split())
    for i in range(n):
        make_dir(sys.stdin.readline().strip().split('/'))
    c = 0
    for i in range(m):
        c += make_dir(sys.stdin.readline().strip().split('/'))
    print 'Case #%d: %d' % (_, c)
