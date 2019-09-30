import sys
import math

def solve(vals, ind):
    if vals[ind-1]==0:
        return -1
    elif vals[ind-1]==1:
        return 0
    else:
        a = solve(vals, ind*2)
        b = solve(vals, ind*2+1)
        if a==-1 and b==-1:
            return -1
        elif a==-1 or b==-1:
            if b==-1:
                b = a
            if vals[ind-1]%100==10:
                return b
            elif vals[ind-1]//100==1:
                return b+1
            else:
                return -1
        else:
            if vals[ind-1]%100==10:
                return min(a, b)
            elif vals[ind-1]//100==1:
                return min(min(a,b)+1,a+b)
            else:
                return a+b

def do_test(input):
    line = input.readline().split(' ')
    M = int(line[0])
    V = int(line[1])
    vals = []
    for i in range(M):
        if i<(M-1)//2:
            line = input.readline().split(' ')
            x = int(line[0])
            C = int(line[1])
            if V==0:
                x = 1-x
            vals.append(x+10+100*C)
        else:
            x = int(input.readline())
            if V==0:
                x = 1-x
            vals.append(x)
    s = solve(vals, 1)
    if s==-1:
        return 'IMPOSSIBLE'
    return str(s)

input = sys.stdin

N = int(input.readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%(case)d: %(answer)s' % \
        {'case': test+1, 'answer': answer}
    sys.stdout.flush()
