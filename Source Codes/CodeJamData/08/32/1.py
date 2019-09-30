import sys
import math

def do_test(input):
    str = input.readline()[:-1]
    L = len(str)
    num = []
    for i in range(L+1):
        num.append([0]*210)
    num[0][0] = 1
    for i in range(L):
        for d in range(1, L-i+1):
            n = int(str[i:i+d]) % 210
            for x in range(210):
                num[i+d][(x+n)%210] += num[i][x]
            if i>0:
                for x in range(210):
                    num[i+d][(x-n)%210] += num[i][x]
    res = 0
    for x in range(210):
        if 0 in [x%2, x%3, x%5, x%7]:
            res += num[L][x]
    return res

input = sys.stdin

N = int(input.readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%(case)d: %(answer)d' % \
        {'case': test+1, 'answer': answer}
