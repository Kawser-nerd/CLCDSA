#!/usr/bin/env python3.1

import sys

def readline():
    return next(sys.stdin).strip()

def readvals(t):
    return map(t, readline().split())

wcache = {}

def winning(a, b):
    global wcache
    if a == b:
        return False
    a, b = sorted((a, b))
    if b % a == 0:
        return True
    if (a, b) in wcache:
#        print('hit {0} {1}'.format(a, b))
        return wcache[a, b]
#    print(list((a, b - i * a) for i in reversed(range(1, b // a + 1))))
    res = any(not winning(a, b - i * a)
              for i in reversed(range(1, b // a + 1)))
    if len(wcache) > 10000000:
        wcache = {}
    wcache[a, b] = res
    return res

#for i in range(1, 72):
#    print(''.join(map(str, map(int, (winning(i, j) for j in range(1, 72))))))

ncases = int(readline())
for caseno in range(ncases):
    a1, a2, b1, b2 = readvals(int)

    res = sum(winning(i, j)
              for i in range(a1, a2 + 1) for j in range(b1, b2 + 1))
    
    print('Case #{}: {}'.format(caseno + 1, res))
    sys.stdout.flush()
