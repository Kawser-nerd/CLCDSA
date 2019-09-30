import argparse, math

ap = argparse.ArgumentParser()
ap.add_argument('input', type=argparse.FileType('r'))
args = ap.parse_args()
toks = args.input.read().split()
toks.reverse()

T = int(toks.pop())
for t in xrange(T):
    N = int(toks.pop())
    K = int(toks.pop())

    p = []
    for n in xrange(N):
        R = int(toks.pop())
        H = int(toks.pop())
        area = 2*R*H
        p.append((R, area))

    p.sort(key=(lambda (R, a): R))

    res = []
    for r in xrange(K-1, N):
        p2 = list(p[:r])
        p2.sort(key=(lambda (R, a): a), reverse=True)
        A = sum(a for R, a in p2[:K-1])

        res.append(p[r][0]**2 + p[r][1] + A)

    r = math.pi*max(res)
    print 'Case #{}: {}'.format(t + 1, r)
