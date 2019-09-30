import sys

def process(num, fin, fout):
    data = fin.readline().strip().split()
    c = int(data[0])
    combos = data[1:c+1]
    d = int(data[c+1])
    dooms = data[c+2:c+d+2]
    liz = data[-1]
    # Brute Force
    c = {}
    for x in combos:
        c[x[0]+x[1]] = x[2]
        c[x[1]+x[0]] = x[2]
    d = {}
    for x in 'QWERASDF':
        d[x] = []
    for x in dooms:
        d[x[0]].append(x[1])
        d[x[1]].append(x[0])
    ans = []
    for x in liz:
        # combine?
        if len(ans) > 0 and x + ans[-1] in c:
            y = ans.pop()
            ans.append(c[x+y])
        # destroy?
        else:
            ans.append(x)
            for y in d[x]:
                if y in ans:
                    ans = []
                    break
    fout.write('[' + ', '.join(ans) + ']')
        
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
