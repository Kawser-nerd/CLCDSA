f = open('A.txt')
T = int(f.readline())
for case in range(T):
    n = int(f.readline())
    a = [int(x) for x in f.readline().split()]
    b = [int(x) for x in f.readline().split()]
    a.sort()
    b.sort()
    b.reverse()
    print "Case #%d: %d" % (case+1, sum(x*y for x,y in zip(a,b)))
    
