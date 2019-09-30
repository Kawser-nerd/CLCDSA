import sys

t = int(sys.stdin.readline())
for _ in range(1,t+1):
    k = int(sys.stdin.readline())
    s = list()
    for i in range(2*k-1):
        s.append(sys.stdin.readline())
    cR = range(2*k-1)
    for i in (range(k-1,-1,-1) + range(k,2*k-1)):
        ncR = list()
        xl = abs(k-1-i)
        xr = 2*(k-1)-abs(k-1-i)
        for j in cR:
            if j <= xl or j >= xr:
                ncR.append(j)
            else:
                if (i+j+k)&1:
                    u,v = j,j
                else:
                    u,v = j-1,j+1
                fl = True
                while u>=xl and v<=xr:
                    if s[i][u] != s[i][v]:
                        fl = False
                        break
                    u -= 2
                    v += 2
                if fl:
                    ncR.append(j)
        del cR
        cR = ncR
    cC = range(2*k-1)
    for i in (range(k-1,-1,-1) + range(k,2*k-1)):
        ncC = list()
        xl = abs(k-1-i)
        xr = 2*(k-1)-abs(k-1-i)
        for j in cC:
            if j <= xl or j >= xr:
                ncC.append(j)
            else:
                if (i+j+k)&1:
                    u,v = j,j
                else:
                    u,v = j-1,j+1
                fl = True
                while u>=xl and v<=xr:
                    if s[u][i] != s[v][i]:
                        fl = False
                        break
                    u -= 2
                    v += 2
                if fl:
                    ncC.append(j)
        del cC
        cC = ncC
    #print cR, cC
    res = min([abs(x-(k-1)) for x in cR])+min([abs(y-(k-1)) for y in cC])
    res = (k+res)**2-k**2
    print 'Case #%d: %d' % (_, res)
