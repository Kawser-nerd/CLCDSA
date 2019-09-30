import sys

th = [0,1,2]

def napln(n,a,b,c,d,x,y,m):
    counts = {}
    for r in th:
        for s in th:
            counts[(r,s)] = 0
    for i in range(n):
        counts[(x%3,y%3)] += 1
        x = (a*x+b)%m
        y = (c*y+d)%m
    return counts


def pocty(counts):
#    print counts
    sum = 0
    dupl = 0
    trupl = 0
    for a in th:
        for b in th:
            trupl += counts[(a,b)]

            dupl += counts[(a,b)]*counts[(a,b)]

            for c in th:
                for d in th:
                    e = (6-a-c) % 3
                    f = (6-b-d) % 3

                    poc = counts[(a,b)]*counts[(c,d)]*counts[(e,f)]
                    sum += poc
#                    if poc>0:
#                        print a,b,c,d,e,f,poc

#    print sum, dupl, trupl
    return (sum - 3*dupl + 2*trupl)/6


sys.stdin.readline()

case = 1
for li in sys.stdin.readlines():
    (n,a,b,c,d,x,y,m) = [int (i) for i in li.split()]
    print "Case #%d: %d" % (case, pocty(napln(n,a,b,c,d,x,y,m)))
    case += 1


