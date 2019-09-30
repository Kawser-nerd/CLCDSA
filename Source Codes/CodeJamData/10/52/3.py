# CodeJam!
import heapq

class Data():
    pass

a = [-1] * 100000

def solve(d):
    global a
    d.b.sort()
    for en in xrange(d.n-1, -1, -1):
        want = d.l % d.b[en]
        for i in xrange(d.b[en]):
            a[i] = -1
        a[0] = (0, 0)
        q = []
        heapq.heappush(q, ((0, 0), 0))
        while q:
            b = heapq.heappop(q)[1]
            for i in xrange(en-1, -1, -1):
                c = (b + d.b[i]) % d.b[en]
                if a[c] == -1 or (a[c][0] - a[c][1]//d.b[en] >
                                  a[b][0] + 1 - (a[b][1] + d.b[i])//d.b[en] ):
                    a[c] = (a[b][0] + 1, a[b][1] + d.b[i])
                    heapq.heappush(q, ((-a[c][1], a[c][0]), c))
        #print a[0:d.b[en]]
        if(a[want] != -1):
            return (d.l - a[want][1]) / d.b[en] + a[want][0]
    return "IMPOSSIBLE"
        
    
def readdata():
    global fin, fout
    nt = int(fin.readline())
    #fout.write(str(nt) + "\n")
    for testnum in range(1, nt+1):
        print testnum
        d = Data()
        d.l, d.n = [int(x) for x in fin.readline().split()]
        d.b = [int(x) for x in fin.readline().split()]
        fout.write("Case #" + str(testnum) + ": " + str(solve(d)) + "\n")

def openfile(name):
    global fin, fout
    if name[-3:] == ".in": name = name[:-3]
    fin = open(name + ".in", 'r')
    fout = open(name + ".out", 'w')

def main(name):
    global fin, fout
    openfile(name)
    readdata()
    fin.close()
    fout.close()
    
