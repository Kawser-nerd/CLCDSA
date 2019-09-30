def solvable(A, motes, adds):
    for m in motes:
        while m >= A and adds > 0:
            A += A - 1
            adds -= 1

        if m >= A:
            return False

        A += m

    return True

def solve_case(test_case):
    A, N = map(int, raw_input().split())
    motes = sorted(map(int, raw_input().split()))
    best = 1000000000

    for adds in xrange(N + 1):
        for removes in xrange(N + 1):
            if solvable(A, motes[:N - removes], adds):
                best = min(best, adds + removes)

    print "Case #{0}: {1}".format(test_case, best)

for test_case in xrange(1, int(raw_input()) + 1):
    solve_case(test_case)