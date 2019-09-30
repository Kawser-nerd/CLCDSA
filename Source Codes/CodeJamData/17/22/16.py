#!/usr/bin/python3

def solve_small(r, y, b):
    if r > y + b or y > r + b or b > r + y:
        return "IMPOSSIBLE"
    rs = 'R'
    ys = 'Y'
    bs = 'B'

    if y >= r and y >= b:
        rs, ys = ys, rs
        r, y = y, r
    elif b >= r and b >= y:
        rs, bs = bs, rs
        r, b = b, r
    if b > y:
        bs, ys = ys, bs
        b, y = y, b

    n = r + y + b

    ans = [rs for i in range(r)]

    for i in range(b):
        ans[i] += bs
    for j in range(b, r):
        ans[j] += ys
    for k in range(r - b, y):
        ans[k - (r - b)] += ys

    return ''.join(ans)


def solve_large(r, o, y, g, b, v):
    if r == g == y == g == 0 and b == o:
        return 'BO' * b
    if r == o == b == g == 0 and y == v:
        return 'YV' * y
    if o == b == v == y == 0 and r == g:
        return 'RG' * r
    if (g > 0 and r < g + 1) or (v > 0 and y < v + 1) or (o > 0 and b < o + 1):
        return "IMPOSSIBLE"
    s = solve_small(r - g, y - v, b - o)
    if s == "IMPOSSIBLE":
        return s
    ans = [s[i] for i in range(len(s))]
    if 'R' in s:
        ri = s.index('R')
        if ri != -1:
            ans[ri] = 'RG' * g + 'R'
    if 'Y' in s:
        yi = s.index('Y')
        if yi != -1:
            ans[yi] = 'YV' * v + 'Y'
    if 'B' in s:
        bi = s.index('B')
        if bi != -1:
            ans[bi] = 'BO' * o + 'B'
    return ''.join(ans)


def verify(s):
    if s == "IMPOSSIBLE":
        return s
    for i in range(len(s)):
        if s[i] == s[i - 1]:
            print(s,i)
        assert(s[i] != s[i - 1])
    return s


def solve():
    n, r, o, y, g, b, v = map(int, input().split())
    return verify(solve_large(r, o, y, g, b, v))


t = int(input())
for i in range(t):
    print("Case #{}: {}".format(i + 1, solve()))
