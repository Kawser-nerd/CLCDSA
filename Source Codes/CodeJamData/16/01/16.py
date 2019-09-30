def solve_case(t):
    N = int(raw_input())
    if N == 0:
        print ("Case #%d: %s" % (t, 'INSOMNIA'))
        return

    digits = set()
    last_num = None
    for i in xrange(1, 120):
        for c in str(i * N):
            digits.add(c)
        if len(digits) == 10:
            last_num = i * N
            break

    assert len(digits) == 10
    print ("Case #%d: %d" % (t, last_num))


T = int(raw_input())
for i in xrange(T):
    solve_case(i + 1)
