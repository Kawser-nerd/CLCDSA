from math import sqrt

global cells
global mem
global P
global Q
def minbribe(start,end):
    if ((start,end) in mem):
        return mem[(start,end)]
    
    min = P*Q
    if start+1 >= end:
        min = 0

    else:
        for c in range(start+1,end):
            bribe = (cells[end] - cells[start] - 2) + minbribe(start, c) + minbribe(c, end)
            if bribe < min:
                min = bribe
    mem[(start,end)] = min
    return min



s = raw_input()
cases = int(s)
for case in range(cases):
    
    s = raw_input()
    n = s.split(' ')
    P = int(n[0])
    Q = int(n[1])

    s = raw_input()
    n = s.split(' ')
    cells = [0] + map(int, s.split(' ')) + [P+1]
    mem = {}
    print 'Case #%d: %d' % ((case+1), minbribe(0, len(cells)-1))
