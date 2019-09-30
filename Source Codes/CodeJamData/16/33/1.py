#!/usr/bin/python

f = 'c-sample.in'
f = 'C-small-attempt0.in'
f = 'C-large.in'

inp = map(str.strip, list(open(f))[1:])

def solve(J, P, S, K):
    options = []
    for j in range(J):
        for p in range(P):
            for k in range(min(S, K)):
                options.append([j, p, (j + p + k)%S])
    N = J * P * min(S, K)
    return str(N) + '\n' + '\n'.join(' '.join(str(x+1) for x in op) for op in options)


# for t, n in enumerate(inp):
    # print 'Case #%d: %s' % (t+1, solve(n))
# T = int(inp.pop(0))
t = 1
while inp:
    vals = map(int, inp.pop(0).split())
    print 'Case #%d: %s' % (t, solve(*vals))
    t += 1