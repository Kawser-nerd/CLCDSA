import sys

def max_flow(c,source,sink):
    n = len(c)
    dc = dict()
    df = dict()
    a = [[] for x in xrange(n)]
    for x in xrange(n):
        for y in c[x]:
            dc[(x,y)] = 1
            dc[(y,x)] = 0
            df[(x,y)] = 0
            df[(y,x)] = 0
            a[x].append(y)
            a[y].append(x)
    res = 0
    while True:
        fr = -1
        visit = [False for x in xrange(n)]
        visit[source] = True
        path = [(source,-1)]
        found = False
        while fr+1<len(path):
            fr += 1
            sn = path[fr][0]
            for en in a[sn]:
                if (not visit[en])and(df[(sn,en)]<dc[(sn,en)]):
                    visit[en] = True
                    path.append((en,fr))
                    if en==sink:
                        found = True
                        break
            if found:
                break
        if not found:
            break
        res += 1
        curr = len(path)-1
        while curr!=0:
            prev = path[curr][1]
            sn = path[prev][0]
            en = path[curr][0]
            df[(sn,en)] += 1
            df[(en,sn)] -= 1
            curr = prev
    return res

def main(ifn='cin.txt',ofn='cout.txt'):
    sys.setrecursionlimit(2000)
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    with open(ifn) as inf:
        with open(ofn,'w') as ouf:
            noc = int(inf.readline())
            for tnoc in xrange(1,noc+1):
                ouf.write("Case #%d: " %(tnoc))
                print "Case #%d: " %(tnoc)
                w,h,b = map(int,inf.readline().strip().split(' '))

                river = [[True for y in xrange(h)] for x in xrange(w)]
                for x in xrange(b):
                    x0,y0,x1,y1 = map(int,inf.readline().strip().split(' '))
                    for i in xrange(x0,x1+1):
                        for j in xrange(y0,y1+1):
                            river[i][j] = False

                n = w*h
                total = n+n+2
                c = [[] for x in xrange(total)]
                for x in xrange(w):
                    for y in xrange(h):
                        if not river[x][y]:
                            continue
                        t = x*h+y
                        c[t].append(n+t)
                        for z in xrange(4):
                            tx = x+dx[z]
                            ty = y+dy[z]
                            if (tx>=0)and(tx<w)and(ty>=0)and(ty<h)and(river[tx][ty]):
                                c[n+t].append(tx*h+ty)
                source = n+n
                sink = n+n+1
                y = 0
                for x in xrange(w):
                    if not river[x][y]:
                        continue
                    c[source].append(x*h+y)
                y = h-1
                for x in xrange(w):
                    if not river[x][y]:
                        continue
                    c[n+x*h+y].append(sink)

                tc = [set(x) for x in c]
                bestAnswer = max_flow(tc,source,sink)

                ouf.write("%d\n" %(bestAnswer))
                print "%d" %(bestAnswer)

