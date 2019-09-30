# encoding: utf-8

def recycled(A, B):
    bs = str(B)
    assert(len(str(A)) == len(str(B)))
    for n in range(A, B):
        ns = str(n)
        for i in range(1, len(ns)):
            ms = ns[i:] + ns[:i]
            if ns < ms <= bs:
                yield (ns, ms)

data = open('C-large.in', 'r')
T = int(data.readline().strip())
for case in range(1, T+1):
    (A, B) = tuple(map(int, data.readline().split()))
    print 'Case #{}: {}'.format(case, len(set(recycled(A, B))))
