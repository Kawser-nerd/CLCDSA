import argparse

ap = argparse.ArgumentParser()
ap.add_argument('input', type=argparse.FileType('r'))
args = ap.parse_args()
toks = args.input.read().split()
toks.reverse()

T = int(toks.pop())
for t in xrange(T):
    Ac = int(toks.pop())
    Aj = int(toks.pop())

    totC = 720
    totJ = 720

    A = []
    for i in xrange(Ac):
        C = int(toks.pop())
        D = int(toks.pop())
        A.append((C, D, 'C'))
        totC -= D - C

    for i in xrange(Aj):
        C = int(toks.pop())
        D = int(toks.pop())
        A.append((C, D, 'J'))
        totJ -= D - C

    exch = 0

    A.sort(key=lambda (C, D, w): C)

    Cs = []
    Js = []

    for i in xrange(0, len(A)):
        prev = i - 1 if i != 0 else len(A) - 1

        if A[prev][2] != A[i][2]:
            exch += 1
            continue

        l = A[i][0] - A[prev][1]
        if l < 0:
            l += 1440

        if A[prev][2] == 'C':
            Cs.append(l)
        else:
            Js.append(l)

    Cs.sort()
    for c in Cs:
        if totC >= c:
            totC -= c
        else:
            exch += 2

    Js.sort()
    for c in Js:
        if totJ >= c:
            totJ -= c
        else:
            exch += 2

    print 'Case #{}: {}'.format(t + 1, exch)
