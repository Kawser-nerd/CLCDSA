import sys
import string
from itertools import combinations

def lowest(line):
    sums = {}
    for n in range(1, len(line)):
        print n
        for c in combinations(line, n):
            if sums.has_key(sum(c)):
                return [c, sums[sum(c)]]
            else:
                sums[sum(c)] = c
    return 'Impossible'

if __name__=='__main__':
    infile = open(sys.argv[1])
    lines = []
    output = []
    infile.readline()
    for line in infile:
        lines.append([int(p) for p in line.split()[1:]])
    caseNum = 1
    for line in lines:
        output.append("Case #" + str(caseNum) + ":")
        sums = lowest(line)
        if sums=='Impossible':
            output.append('Impossible')
        else:
            output.append(' '.join([str(i) for i in sums[0]]))
            output.append(' '.join([str(i) for i in sums[1]]))
        caseNum += 1
    out = open('out.out', 'w')
    for line in output:
        out.write(line + '\n')
