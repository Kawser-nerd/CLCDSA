#!/usr/local/bin/pypy
# run with PyPy 2.6.1

def read_strings():
    return raw_input().strip().split(' ')

def read_ints():
    return [int(x) for x in read_strings()]

IMPOSSIBLE = 'IMPOSSIBLE'
COLORS = 'RYB'
COMP_COLORS = 'GVO'

def solve(n, a):
    for i in xrange(len(a)):
        if 2 * a[i] > n:
            return IMPOSSIBLE
    ans = ['_'] * n
    b = [(a[i], COLORS[i]) for i in xrange(3)]
    b = list(reversed(sorted(b)))
    p = 0
    for i in xrange(3):
        for j in xrange(b[i][0]):
            while ans[p] != '_':
                p = (p + 1) % N
            ans[p] = b[i][1]
            p = (p + 2) % n
    return ''.join(ans)

def replace_once(s, ch, block):
    for i in xrange(len(s)):
        if s[i] == ch:
            return s[:i] + block + s[i + 1:]

def solve_full(n, a, comp):
    for i in xrange(3):
        if 2 * a[i] > n:
            return IMPOSSIBLE
    b = [0] * 3
    for i in xrange(3):
        b[i] = a[i] - comp[i]
        if b[i] < 0:
            return IMPOSSIBLE
        if b[i] == 0:
            if a[i] > 0 and a[i] + comp[i] < n:
                return IMPOSSIBLE
            if a[i] + comp[i] == n:
                return (COLORS[i] + COMP_COLORS[i]) * a[i]
        # b[i] >= 0
    n1 = sum(b)

    ans = solve(n1, b)
    if ans == IMPOSSIBLE:
        return ans

    for i in xrange(3):
        if comp[i] > 0:
            block = (COLORS[i] + COMP_COLORS[i]) * comp[i] + COLORS[i]
            ans = replace_once(ans, COLORS[i], block)
    return ans

# print replace_once('ABRACADABRA', 'B', 'XXX')

test_count, = read_ints()
for test in xrange(1, test_count + 1):
    N, R, O, Y, G, B, V = read_ints()

    ans = solve_full(N, [R, Y, B], [G, V, O])
    print 'Case #{}: {}'.format(test, ans)
