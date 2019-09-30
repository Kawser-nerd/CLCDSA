def nextperm(L):
    l = len(L)

    max = None
    for i in xrange(2, l + 1):
        if L[-i] < L[-i + 1]:
            max = i
            break
    if max is None:
        return nextperm(['0'] + L)

    for j in xrange(1, l + 1):
        if L[-j] > L[-max]:
            break

    L[-max], L[-j] = L[-j], L[-max]

    max -= 1
    a, b = L[:-max], L[-max:]
    b.reverse()
    return a + b

N = int(raw_input())
for i in xrange(1, N + 1):
    L = list(raw_input())
    print 'Case #%d: %s' % (i, ''.join(nextperm(L)))
