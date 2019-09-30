name = 'C'
typ = 'small'
base = name+'-'+typ+'.'
lines = file(base+'in').readlines()

lines = [line.replace('\n','') for line in lines]

T = int(lines[0])
fpos = 1

def crosses(a,b):
    if a[-1] == b[-1]: return True
    for i in xrange(len(a)-1):
        if a[i] > b[i] and a[i+1] < b[i+1] \
        or a[i] < b[i] and a[i+1] > b[i+1] \
        or a[i] == b[i]:
            return True
    return False

def solve(data):
    size = len(data)
    cross = [[False for i in xrange(size)] for i in xrange(size)]
    for a in xrange(size):
        for b in xrange(a,size):
            if crosses(data[a],data[b]):
                cross[a][b] = cross[b][a] = True
    groups = 0
    unused = range(size)
    unused = sorted(unused,key=lambda x:-sum(cross[x]))
    while len(unused):
        groups += 1
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
        print gr
    print cross
    print groups
    return groups

out = file(base+'out','wb')
for case in xrange(1,T+1):
    n,k = [int(i) for i in lines[fpos].split(' ')]
    fpos += 1
    data = [[int(i) for i in line.split(' ')] for line in lines[fpos:fpos+n]]
    fpos += n
    out.write('Case #%d: %d\n' % (case,solve(data)))

out.close()
