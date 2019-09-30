import sys

def process(num, fin, fout):
    n = int(fin.readline())
    data = [int(x) for x in fin.readline().split()]
    unmatched = 0
    for i in xrange(len(data)):
        if data[i] != i+1:
            unmatched += 1
    fout.write(str(unmatched))

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
