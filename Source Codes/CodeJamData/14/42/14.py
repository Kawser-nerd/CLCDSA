import sys

def main(ifn='bin.txt',ofn='bout.txt'):
    sys.setrecursionlimit(2000)
    with open(ifn) as inf:
        with open(ofn,'w') as ouf:
            noc = int(inf.readline())
            for tnoc in xrange(1,noc+1):
                ouf.write("Case #%d: " %(tnoc))
                print "Case #%d: " %(tnoc)
                n = int(inf.readline())
                a = map(int,inf.readline().strip().split(' '))
                answer = 0
                while len(a)>0:
                    target = min(a)
                    ind = a.index(target)
                    answer += min(ind,abs(ind-(len(a)-1)))
                    a.remove(target)
                ouf.write("%d\n" %(answer))
                print "%d" %(answer)

