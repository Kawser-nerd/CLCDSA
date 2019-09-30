import copy
import math

infile = open('C-small-attempt0.in').readlines()
infile = [line.strip() for line in infile]
wfile = open('result', 'w')
T = int(infile[0])
infile = infile[1:]

prime = [2,]
for i in range(3, 1000):
    for t in prime:
        if i % t == 0:
            break
    else:
        prime.append(i)


for case_no in range(1, T+1):
    N = int(infile[0])
    infile = infile[1:]
    result = 0
    sqr = int(math.sqrt(N))
    for i in range(2, sqr+2):
        if i not in prime:
            continue
        tmp = i
        while True:
            tmp *= i
            if (tmp<=N):
                result += 1
            else:
                break
    result += 1
    if N== 1:
        result = 0
    wfile.write('Case #%s: %s\n' % (case_no, result))
    