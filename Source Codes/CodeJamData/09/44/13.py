name = 'D'
typ = 'small'
base = name+'-'+typ+'.'
lines = file(base+'in').readlines()

lines = [line.replace('\n','') for line in lines]

C = int(lines[0])
fpos = 1

def get_dist(a,b):
    d_x = a[0]-b[0]
    d_y = a[1]-b[1]
    dist = (d_x*d_x+d_y*d_y)**0.5 + a[2]+b[2]
    return dist

def get_largest(dist):
    size = len(dist)
    largest = (0,0)
    largest_dist = -1
    for a in xrange(size):
        for b in xrange(a+1,size):
            if dist[a][b] > largest_dist:
                largest_dist = dist[a][b]
                largest = (a,b)
    return largest

def erase_largest(dist):
    size = len(dist)
    dist = [[dist[b][a] for a in xrange(size)] for b in xrange(size)]
    largest = (0,0)
    largest_dist = -1
    for a in xrange(size):
        for b in xrange(a+1,size):
            if dist[a][b] > largest_dist:
                largest_dist = dist[a][b]
                largest = (a,b)
    a,b = largest
    dist[a][b] = dist[b][a] = 0
    return dist

def split(dist):
    cross = [[not bool(c) for c in row] for row in dist]
    size = len(dist)
    unused = range(size)
    unused = sorted(unused,key=lambda x:-sum(cross[x]))
    groups = 0
    ret = []
    while len(unused):
        groups += 1
        if groups > 2: return None
        gr = [unused.pop(0)]
        topop = []
        for new in xrange(len(unused)):
            for old in gr:
                if cross[old][unused[new]]:
                    break
            else:
                gr.append(unused[new])
                topop.append(new)
        poped = 0
        for pop in topop:
            unused.pop(pop-poped)
            poped += 1
        ret.append(gr)
    return ret


def solve(data):
    size = len(data)
    if size == 1: return float(data[0][2])
    if size == 2: return float(max(data[0][2],data[1][2]))
    dist = [[0 for i in xrange(size)] for j in xrange(size)]
    for a in xrange(size):
        for b in xrange(size):
            dist[a][b] = get_dist(data[a],data[b])
    newdist = erase_largest(dist)
    newgr = split(newdist)
    while newgr:
        dist = newdist
        gr = newgr
        newdist = erase_largest(dist)
        newgr = split(newdist)
    ops = []
    for g in gr:
        grdist = [[dist[b][a] for a in g] for b in g]
        a,b = get_largest(grdist)
        ops.append(grdist[a][b])
    return max(ops)/2.0

out = file(base+'out','wb')
for case in xrange(1,C+1):
    print case
    n = int(lines[fpos])
    fpos += 1
    data = [[int(var) for var in line.split(' ')] for line in lines[fpos:fpos+n]]
    fpos += n
    out.write('Case #%d: %.7f\n' % (case, solve(data)))


out.close()
