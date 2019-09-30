

def add_dir(map, dir):
    new_dirs = 0

    dirs = dir.split('/')[1:]
    while dirs:
        if dirs[0] not in map:
            new_dirs += 1
            map[dirs[0]] = {}
        map = map[dirs[0]]
        dirs = dirs[1:]
    return new_dirs

fin = open('in', 'r')
test_count = int(fin.readline().rstrip())
for t in xrange(test_count):
    n, m = [int(x) for x in fin.readline().rstrip().split()]
    
    dirs = {}
    
    for i in xrange(n):
        dir = fin.readline().rstrip()
        add_dir(dirs, dir)
    
    new_dirs = 0
    for i in xrange(m):
        dir = fin.readline().rstrip()
        new_dirs += add_dir(dirs, dir)
    
    print 'Case #%d: %d' % (t + 1, new_dirs)
