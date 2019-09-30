def trans(a):
    return map(lambda x: ''.join(list(x)), zip(*a))

def can(r, c, m):
    if r > c: r, c = c, r

    safe = r * c - m
    if r == 1 or safe == 1:
        return True
    elif r == 2:
        return safe % 2 == 0 and safe >= 4
    else:
        return not safe in [2, 3, 5, 7]

def solve(r, c, m):
    if not can(r, c, m):
        print 'Impossible'
        return

    swapped = False
    if r > c: r, c, swapped = c, r, True

    ans, safe = [['.'] * c for _ in xrange(r)], r * c - m
    if r == 1:
        for i in xrange(safe, c):
            ans[0][i] = '*'
    elif r == 2:
        for i in xrange(safe // 2, c):
            ans[0][i] = ans[1][i] = '*'
    elif m <= (r - 2) * (c - 2):
        for i in xrange(m):
            ans[r - i % (r - 2) - 1][c - i // (r - 2) - 1] = '*'
    else:
        ans = [['*'] * c for _ in xrange(r)]
        if safe <= 6:
            for i in xrange(safe // 2):
                ans[i][0] = ans[i][1] = '.'
        else:
            for i in xrange(8):
                ans[i % 3][i // 3] = '.'
            safe -= 8
            if safe % 2 == 1:
                ans[2][2] = '.'
                safe -= 1
            a = min(r - 3, safe // 2)
            for i in xrange(a):
                ans[3 + i][0] = ans[3 + i][1] = '.'
            safe -= 2 * a
            for i in xrange(safe // 2):
                ans[0][3 + i] = ans[1][3 + i] = '.'

    ans[0][0] = 'c'
    if swapped: ans = trans(ans)
    for row in ans: print ''.join(row)

T = input()
for i in xrange(T):
    [r, c, m] = map(int, raw_input().split())
    print 'Case #%d:' % (i + 1)
    solve(r, c, m)
