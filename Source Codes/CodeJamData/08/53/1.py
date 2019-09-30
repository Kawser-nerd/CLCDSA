import sys
import math

cnt = [0]*1024
for x in range(1024):
    s = 0
    for b in range(10):
        if x & (1<<b):
            s += 1
    cnt[x] = s

next = []
for x in range(1024):
    nn = []
    for y in range(1024):
        if ((x<<1)|(x<<2)|(x<<3))&(y<<2):
            pass
        else:
            nn.append(y)
    next.append(nn)
    
def do_test(input):
    line = input.readline().split(' ')
    M = int(line[0])
    N = int(line[1])
    broken = []
    brmap = [0]*N
    for i in range(M):
        row = []
        line = input.readline()[:N]
        for j in range(N):
            if line[j]=='x':
                brmap[j] |= 1<<i
    P = (1<<M)
    res = [0]*P
    for i in range(N):
        res2 = [0]*P
        for x in range(P):
            for y in next[x]:
                if y<P and ((y&brmap[i])==0):
                    res2[y] = max(res2[y], res[x]+cnt[y])
        res = res2
    rr = 0
    for i in res:
        rr = max(rr, i)
    
    return str(rr)

input = sys.stdin

N = int(input.readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%(case)d: %(answer)s' % \
        {'case': test+1, 'answer': answer}
    sys.stdout.flush()
