#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p3.out", "w")

fin.readline()
N, J = map(int, fin.readline().split())

fout.write("Case #1:\n")

def conv_base(l, base):
    ret = 1 + base ** (N - 1)
    ret += sum(map(lambda x: base ** x, l))
    return ret

def lcp(n):
    for m in xrange(2, min(n, 1000)):
        if n % m == 0:
            return m
    return -1

ans = {3: 2, 4: 3, 5: 2, 7: 2, 9: 2, 10: 3}
cur = [1, 2, 3, 4]
while J > 0:
    # increment cur
    j = 3
    for i in xrange(len(cur) - 1):
        if cur[i] + 1 == cur[i + 1]:
            continue
        else:
            j = i
            break
    cur[j] += 1
    for i in xrange(j):
        cur[i] = i + 1

    # end increment cur
    ans[2] = lcp(conv_base(cur, 2))
    ans[6] = lcp(conv_base(cur, 6))
    ans[8] = lcp(conv_base(cur, 8))
    if ans[2] < 0 or ans[6] < 0 or ans[8] < 0:
        continue
    else:
        J -= 1
        fout.write(str(conv_base(cur, 10)) + ' ')
        for i in xrange(2, 10):
            fout.write(str(ans[i]) + ' ')
        fout.write(str(ans[10]) + '\n')
