import sys
import math

def solve(cards):
    if len(cards)==0:
        return 0
    counts = [0]*10010
    for c in cards:
        counts[c]+=1
    ups = []
    downs = []
    for i in range(10010-1):
        d = counts[i+1]-counts[i]
        if d>0:
            for j in range(d):
                ups.append(i)
        if d<0:
            for j in range(-d):
                downs.append(i)
    return min(d-u for u,d in zip(ups,downs))            

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    line = readline().split()
    assert len(line)==int(line[0])+1
    cards = [int(x) for x in line[1:]]
    res = solve(cards)
    return str(res)

input = sys.stdin

N = int(readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%d: %s' % (test+1, answer)
    sys.stdout.flush()
    
