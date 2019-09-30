import sys
import os

# google for clasp and lparse to handle the files

def do_one(casenum):
    N,K=map(int,sys.stdin.readline().strip().split())
    confl = [[False]*N for i in xrange(0,N)]
    charts = [None]*N

    for i in xrange(0,N):
        charts[i] = map(int,sys.stdin.readline().strip().split())
        for j in xrange(0,i):
            for t in xrange(0,K-1):
                if (charts[i][t] == charts[j][t] or
                    charts[i][t+1] == charts[j][t+1] or
                    (charts[i][t] < charts[j][t]) !=
                    (charts[i][t+1] <charts[j][t+1])):
                    confl[i][j] = True
                    confl[j][i] = True
                    break

    f = open("out.lp","w")
    #f = os.popen("cat","w")

    print >>f, "stock(0..%d)." % N

    for i in xrange(0,N):
        for j in xrange(0,N):
            if confl[i][j]:
                print >>f, "conflict(%d,%d)." % (i,j)

    print >>f, ":- include(Chart,A), include(Chart,B), conflict(A,B), stock(A;B;Chart)."
    print >>f, "1 { include(C,S) : stock(C) } 1 :- stock(S)."
    print >>f, "empty(Chart) :- 0 { include(Chart,S) : stock(S) } 0, stock(Chart)."
    print >>f, ":- empty(N-1), not empty(N), stock(N)."
    print >>f, "include(0,0)."
    ne = 1
    li = [0]
    for i in xrange(1,N):
        confall = True
        for j in li:
            if not confl[i][j]:
                confall = False
                break
        if confall:
            print >>f, "include(%d,%d)." % (ne,i)
            ne += 1
            li.append(i)
                
        
    print >>f, "maximize { empty(C) : stock(C) }."

    f.close()
    f = os.popen("lparse --true-negation <out.lp |clasp --number=0")

    best = 99999
    for li in f:
        #print li.strip()
        if li.find('include(') != -1:
            best = N-li.count('empty(')+1

    assert best != 99999

    #sys.exit(0)
    print "Case #%d: %d" % (casenum,best)
    
    
    

def main():
    T = int(sys.stdin.readline())
    for i in xrange(1,T+1):
        do_one(i)

main()
