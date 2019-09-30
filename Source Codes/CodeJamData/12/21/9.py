import sys
import string
from itertools import combinations

def lowest(line):
    X = sum(line)
    srted = sorted(line)
    out = [0]*len(line)
    ptsRemaining = X
    linecopy = line
    best = 0
    for n in srted:
        if sum([max(n - l, 0) for l in line]) <= X:
            best = n
    lower = [best - l for l in line if best - l >= 0]
    diff = sum(lower)
    ptsRemaining = X - diff
    distPts = ptsRemaining/float(len(lower))
    #print best, distPts, lower
    linecopy = list(line)
    for i in range(len(linecopy)):
        if linecopy[i] < best + distPts:
            linecopy[i] = best + distPts
    for i in range(len(linecopy)):
        if linecopy[i] > line[i]:
            out[i] = 100*(linecopy[i] - line[i])/float(X)
    return out

if __name__=='__main__':
    infile = open(sys.argv[1])
    lines = []
    output = []
    infile.readline()
    for line in infile:
        lines.append([int(p) for p in line.split()[1:]])
    caseNum = 1
    for line in lines:
        print caseNum
        output.append("Case #" + str(caseNum) + ": " + 
                      ' '.join([str(l) for l in lowest(line)]))
        caseNum += 1
    out = open('out.out', 'w')
    for line in output:
        out.write(line + '\n')
