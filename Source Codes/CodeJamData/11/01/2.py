import sys

def process(num, fin, fout):
    data = fin.readline().strip().split()
    n = int(data[0])
    robots = ['O', 'B'] + [data[2*i+1] for i in xrange(n)]
    poss = [1, 1] + [int(data[2*i+2]) for i in xrange(n)]
    ans = [0, 0]
    for i in xrange(2, len(robots)):
        r = robots[i]
        j = i - 1
        while robots[j] != r:
            j -= 1
        ans.append(max(ans[j] + abs(poss[i] - poss[j]) + 1, ans[i-1] + 1))
    fout.write(str(ans[-1]))

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
