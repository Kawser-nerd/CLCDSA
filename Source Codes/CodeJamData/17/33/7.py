import argparse

ap = argparse.ArgumentParser()
ap.add_argument('input', type=argparse.FileType('r'))
args = ap.parse_args()
toks = args.input.read().split()
toks.reverse()

T = int(toks.pop())
for t in xrange(T):
    N = int(toks.pop())
    K = int(toks.pop())
    U = float(toks.pop())
    P = [float(toks.pop()) for i in xrange(N)]

    assert N == K

    P.sort()

    span = 1

    while True:
        while span < len(P) and P[0] == P[span]:
            span += 1

        if span == len(P):
            P[0] += U / span
            break

        next = P[span]
        need = span * (next - P[0])
        if U >= need:
            U -= need
            P[0] = next
        else:
            P[0] += U / span
            break

    for i in xrange(1, span):
        P[i] = P[0]

    r = 1
    for p in P:
        r *= p

    print 'Case #{}: {}'.format(t + 1, r)
