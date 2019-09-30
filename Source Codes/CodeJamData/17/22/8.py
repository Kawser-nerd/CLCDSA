#!/usr/bin/env python3
from itertools import zip_longest

def find_str(n, r, o, y, g, b, v):
    fail = 'IMPOSSIBLE'
    # y -> v, r -> g, b -> o
    # corner cases
    if r == g and r + g == n:
        return 'RG' * r
    if y == v and y + v == n:
        return 'YV' * y
    if b == o and b + o == n:
        return 'BO' * b
    if g >= max(r, 1) or v >= max(y, 1) or o >= max(b, 1):
        return fail
    r -= g
    y -= v
    b -= o
    if max(r, y, b) * 2 > r + y + b:
        return fail
    s = sorted(list(zip('RYB', [r, y, b])), key=lambda x: -x[1])
    c, cnt = list(zip(*s))
    p1 = c[0] * cnt[0]
    p2 = c[1] * cnt[1] + c[2] * cnt[2]
    p2, p3 = p2[:cnt[0]], p2[cnt[0]:]
    ans = ''.join(''.join(v) for v in zip_longest(p1, p2, p3, fillvalue=''))
    ans = ans.replace('R', 'RG' * g + 'R', 1)
    ans = ans.replace('Y', 'YV' * v + 'Y', 1)
    ans = ans.replace('B', 'BO' * o + 'B', 1)
    return ans

def ok(c1, c2):
    for it in range(2):
        if c1 == 'V' and c2 not in 'Y':
            return False
        if c1 == 'G' and c2 not in 'R':
            return False
        if c1 == 'O' and c2 not in 'B':
            return False
        c1, c2 = c2, c1
    return True

def validate(s):
    if s == 'IMPOSSIBLE':
        return
    for c1, c2 in zip(s, s[1:]):
        if not ok(c1, c2):
            print('Fail 1')
            print(s, c1, c2)
            raise ValueError
    if not ok(s[0], s[-1]):
        print('Fail 2')
        raise ValueError

def process_test(test_id):
    ans = find_str(*list(map(int, input().split())))
    validate(ans)
    print('Case #{:d}: {:s}'.format(test_id, ans))


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        process_test(i + 1)
