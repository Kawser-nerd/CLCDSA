def solve(ap, bp, A, B):
    global memo

    #print ap, bp, A, B

    if not A or not B:
        return 0
    if (ap, bp) in memo:
        return memo[ap, bp]
    if A[0][0] == 0:
        return solve(ap, bp, A[1], B)
    if B[0][0] == 0:
        return solve(ap, bp, A, B[1])

    Atop = A[0]
    Btop = B[0]
    # pack as many toys as possible
    if Atop[1] == Btop[1]:
        packed = min(Atop[0], Btop[0])
        ap_ = ap + packed
        bp_ = bp + packed
        A_ = ((Atop[0]-packed, Atop[1]), A[1])
        B_ = ((Btop[0]-packed, Btop[1]), B[1])

        ans = packed + solve(ap_, bp_, A_, B_)
        memo[ap, bp] = ans
        return ans
    else:
        # either discard A's
        ap_ = ap + Atop[0]
        A_ = A[1]
        discA = solve(ap_, bp, A_, B)

        # or B's
        bp_ = bp + Btop[0]
        B_ = B[1]
        discB = solve(ap, bp_, A, B_)

        ans = max(discA, discB)
        memo[ap, bp] = ans
        return ans

def linked_list(xs, i=0):
    if i == len(xs):
        return ()
    else:
        return (xs[i], linked_list(xs, i+1))

T = int(raw_input())
for case in xrange(1, T+1):
    memo = {}
    N, M = map(int, raw_input().split())
    A = map(int, raw_input().split())
    A = linked_list(zip(A[::2], A[1::2]))

    B = map(int, raw_input().split())
    B = linked_list(zip(B[::2], B[1::2]))

    print 'Case #%i: %i' % (case, solve(0, 0, A, B))
