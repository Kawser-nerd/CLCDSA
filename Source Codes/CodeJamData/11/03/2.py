import sys

def process(num, fin, fout):
    n = int(fin.readline())
    data = fin.readline().strip().split()
    c = [int(x) for x in data]
    for i in xrange(20):
        s = sum([x >> i for x in c])
        if s % 2 != 0:
            fout.write("NO")
            return
    fout.write("%d" % (sum(c) - min(c)))

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print "Please indicate input and output"
        exit(0)
    fin = open(sys.argv[1], 'r')
    fout = open(sys.argv[2], 'w')
    times = int(fin.readline())
    for i in xrange(times):
        fout.write("Case #%d: " % (i+1))
        process(i, fin, fout)
        fout.write("\n")
    fin.close()
    fout.close()
