def binom(n, r):
    p = 1.0

    for i in xrange(r):
        p = p * (n - i) / (i + 1)

    return p

def solve_case(test_case):
    N, X, Y = map(int, raw_input().split())
    k = 1

    while (k + 2) * (k + 3) // 2 <= N:
        k += 2

    assert k % 2 == 1
    level = abs(X) + Y + 1
    assert level % 2 == 1

    if level <= k:
        print "Case #{0}: 1.0".format(test_case)
        return

    if level > k + 2:
        print "Case #{0}: 0.0".format(test_case)
        return

    assert level == k + 2
    d = N - k * (k + 1) // 2
    h = k + 1
    assert d <= 2 * h

    if Y == h:
        print "Case #{0}: 0.0".format(test_case)
        return

    if d > h and Y < d - h:
        print "Case #{0}: 1.0".format(test_case)
        return

    prob = 0.0

    for i in xrange(Y + 1, d + 1):
        prob += binom(d, i)

    prob /= 2**d
    print "Case #{0}: {1}".format(test_case, prob)

for test_case in xrange(1, int(raw_input()) + 1):
    solve_case(test_case)