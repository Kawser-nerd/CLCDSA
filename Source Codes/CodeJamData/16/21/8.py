import sys

tn = int(sys.stdin.readline())

for ti in xrange(tn):
    s = sys.stdin.readline().strip()
    d = {}
    for c in s:
        if c not in d:
            d[c] = 1
        else:
            d[c] += 1
    x = [0]*10
    x[0] = d.get('Z', 0)
    x[2] = d.get('W', 0)
    x[4] = d.get('U', 0)
    x[6] = d.get('X', 0)
    x[8] = d.get('G', 0)
    x[1] = d.get('O', 0) - x[0] - x[2] - x[4]
    x[3] = d.get('R', 0) - x[0] - x[4]
    x[5] = d.get('F', 0) - x[4]
    x[7] = d.get('S', 0) - x[6]
    x[9] = d.get('I', 0) - d.get('F', 0) + x[4] - x[6] - x[8]
    sol = ''.join([chr(ord('0')+i)*x[i] for i in xrange(10)])
    print 'Case #{0}: {1}'.format(ti+1, sol)
