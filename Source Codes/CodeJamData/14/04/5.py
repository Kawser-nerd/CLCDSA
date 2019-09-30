def solve(n, a, b):
    i, j, ans = 0, 0, 0
    while i < n and j < n:
        if a[i] < b[j]:
            i += 1
        else:
            i += 1; j += 1; ans += 1
    return ans + n - i

T = input()
for i in xrange(T):
    n = input()
    a = sorted(map(float, raw_input().split()))
    b = sorted(map(float, raw_input().split()))
    print 'Case #%d: %d %d' % (i + 1, solve(n, a, b), n - solve(n, b, a))
