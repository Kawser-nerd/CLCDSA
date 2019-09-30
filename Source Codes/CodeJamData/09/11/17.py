import sys
fin = file(sys.argv[1], 'r')
T = int(fin.readline())

def happy(x, b):
    prev = x
    #print 'test ', x, b
    prev = [0]
    while True:
        v = 0
        while x > 0:
            v += (x%b) * (x%b)
            x = x / b
        #print v
        if v == 1: return True
        if v in prev: return False
        prev.append(v)
        x = v

for t in xrange(1, T+1):
    bases = [int(x) for x in fin.readline().split()]
    m = 2
    while True:
        if all(happy(m, b) for b in bases):
            break
        m += 1
    print 'Case #%d: %d' % (t, m)
