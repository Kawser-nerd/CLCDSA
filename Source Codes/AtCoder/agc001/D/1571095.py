#!/usr/bin/env python3
def solve(n, m, a):
    odd = []
    even = []
    for a_i in a:
        if a_i % 2 == 0:
            even += [ a_i ]
        else:
            odd += [ a_i ]
    if len(odd) >= 3:
        return None
    a, b = [], []
    if odd:
        x = odd.pop()
        a += [ x ]
        b += [ x - 1 ]
    else:
        x = even.pop()
        a += [ x ]
        b += [ x - 1 ]
    a += even
    b += even
    if odd:
        x = odd.pop()
        a += [ x ]
        b += [ x + 1 ]
    else:
        b += [ 1 ]
    return a, b

n, m = map(int, input().split())
a = list(map(int, input().split()))
it = solve(n, m, a)
if it is None:
    print('Impossible')
else:
    a, b = it
    b = list(filter(lambda b_i: b_i, b))
    print(*a)
    print(len(b))
    print(*b)