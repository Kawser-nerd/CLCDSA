ip = lambda : map(int, raw_input().split())

def solve(cas):
    print 'Case #%d:' % cas,
    N, R, O, Y, G, B, V = ip()
    if Y + V == N:
        if Y != V:
            print "IMPOSSIBLE"
        else:
            s = []
            for i in xrange(Y):
                s.append('Y')
                s.append('V')
            print ''.join(s)
        return
    if O + B == N:
        if O != B:
            print "IMPOSSIBLE"
        else:
            s = []
            for i in xrange(O):
                s.append('O')
                s.append('B')
            print ''.join(s)
        return
    if R + G == N:
        if R != G:
            print "IMPOSSIBLE"
        else:
            s = []
            for i in xrange(R):
                s.append('R')
                s.append('G')
            print ''.join(s)
        return
    if (O > 0 and O + 1 > B) or (G > 0 and G + 1 > R) or (V > 0 and V + 1 > Y):
        print "IMPOSSIBLE"
        return
    OB = []
    OY = []
    OR = []
    if B > 0:
        B -= O + 1
        OB = ['B'] * B
        s = ['B']
        for i in xrange(O):
            s.append('O');
            s.append('B')
        OB.append(''.join(s))
    if R > 0:
        R -= G + 1
        OR = ['R'] * R
        s = ['R']
        for i in xrange(G):
            s.append('G')
            s.append('R')
        OR.append(''.join(s))
    if Y > 0:
        Y -= V + 1
        OY = ['Y'] * Y
        s = ['Y']
        for i in xrange(V):
            s.append('V')
            s.append('Y')
        OY.append(''.join(s))
    C = [[len(OR), OR], [len(OY), OY], [len(OB), OB]]
    C.sort()
    C.reverse()
    if C[1][0] + C[2][0] < C[0][0]:
        print "IMPOSSIBLE"
        return
    s = []
    x = C[0][0]
    y = C[1][0]
    z = C[2][0]
    e = y + z - x
    for i in xrange(0, e * 3, 3):
        s.append(C[0][1].pop())
        s.append(C[1][1].pop())
        s.append(C[2][1].pop())
    x -= e
    y -= e
    z -= e
    for i in xrange(x):
        s.append(C[0][1].pop())
        if y > 0:
            s.append(C[1][1].pop())
            y -= 1
        else:
            s.append(C[2][1].pop())
            z -= 1
    print ''.join(s)

for i in xrange(int(raw_input())):
    solve(i + 1)
