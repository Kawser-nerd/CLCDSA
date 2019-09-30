import math

tcs = int(input())

for tc in range(1, tcs+1):
    a, n = (int(i) for i in input().split(' '))

    ss = list(sorted(int(i) for i in input().split(' ')))

    res = len(ss)

    if a > 1:
        tmp = 0
        for i in range(len(ss)):
            s = ss[i]
            while a <= s:
                tmp += 1
                a += a-1
            a += s
            res = min(res, tmp + len(ss) - 1 - i)

    print("Case #%d: %d" % (tc, res))
