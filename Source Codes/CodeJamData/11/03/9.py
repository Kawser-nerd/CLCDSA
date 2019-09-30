#print 

infile = "C-large.in"

debug=True

def PatrickAdd(L):
    return reduce(lambda a,b: a^b, L)

def solve(nstr, datastr):
    N = int(nstr)
    data = map(int, datastr.split())
    assert len(data) == N
    if PatrickAdd(data) != 0 or len(data) < 2:
        return "NO"
    candy = min(data)
    data.remove(candy)
    assert len(data) == N-1
    assert PatrickAdd(data) == candy
    return sum(data)

def main():
    i = file(infile)
    N = int(i.readline())
    for n in xrange(N):
        soln = solve(i.readline(), i.readline())
        print "Case #%d: %s" % (n+1, soln)

main()

