import sys
import math

def solve(P, wh):
    nbh = [None] * P
    wh = wh + [(y,x) for x, y in wh]
    for x, y in wh:
        if nbh[x] is None:
            nbh[x] = []
        nbh[x].append(y)
    distance = [-1] * P
    maxthr = [[] for x in range(P)]
    ep = set([0])
    distance[0] = 0
    maxthr[0].append((-1,len(nbh[0])))
    d0 = 0
    while 1 not in ep:
        ep2 = set()
        for x in ep:
            for y in nbh[x]:
                if distance[y]<0:
                    a = len(nbh[x])
                    b = len(nbh[y])
                    mxthr = -1
                    for s, thr in maxthr[x]:
                        th = thr - 1 + b
                        ll = nbh[x] + [x]
                        if s>=0:
                            ll += nbh[s]
                        ss = set(ll)
                        for tt in nbh[y]:
                            if tt in ss:
                                th -= 1
                        mxthr = max(mxthr, th)
                    maxthr[y].append((x, mxthr))
                    ep2.add(y)
        d0 += 1
        for y in ep2:
            distance[y] = d0
        ep = ep2
    ddd = distance[1]
    mx = 0
    for s, thr in maxthr[1]:
        for s2, thr2 in maxthr[s]:
            mx = max(mx, thr2)
    return ddd-1, mx
    

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    line = readline().split()
    P = int(line[0])
    W = int(line[1])
    line = readline().split()
    assert len(line)==W
    wh = []
    for s in line:
        spl = s.partition(',')
        wh.append((int(spl[0]), int(spl[2])))
    res = solve(P, wh)
    return res

input = sys.stdin

N = int(readline())

for test in range(N):
    ans1, ans2 = do_test(input)
    print 'Case #%d: %s %s' % (test+1, ans1, ans2)
    sys.stdout.flush()
    
