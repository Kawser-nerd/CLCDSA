def mkseq(p,q,r,s,N):
    return [((i * p + q) % r + s) for i in range(N)]

def has_bound_3_split(seq, bound):
    lsum = 0
    lend = 0
    for i in range(len(seq)):
        if lsum + seq[i] <= bound and i < len(seq)-1:
            lsum += seq[i]
            lend = i+1
        else:
            break


    rsum = 0
    rbegin = len(seq)
    for i in range(len(seq)-1, -1, -1):
        if rsum + seq[i] <= bound and i > lend:
            rsum += seq[i]
            rbegin = i
        else:
            break

    msum = sum(seq[lend:rbegin])

    return msum <= bound, lsum + rsum + msum, max(lsum, rsum, msum)



def search_max_bnd(seq):
    hs, sm, mx = has_bound_3_split(seq, 1)

    if hs:
        return float(sm-mx) / sm


    L = 1
    U = 10**15

    while L + 1 < U:
        M = (L + U) / 2

        hs, sm, mx = has_bound_3_split(seq, M)

        if hs:
            U = M
        else:
            L = M


    hs, sm, mx = has_bound_3_split(seq, U)
    assert hs
    return float(sm-mx) / sm


import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            N, p, q, r, s  = map(int, inf.readline().split())
            seq = mkseq(p,q,r,s,N)
            outf.write('Case #{}: {}\n'.format(t, search_max_bnd(seq)))
