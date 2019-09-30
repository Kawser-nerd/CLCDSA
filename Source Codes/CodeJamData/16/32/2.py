#!/usr/bin/python

f = 'b-sample.in'
f = 'B-small-attempt1.in'
f = 'B-large.in'

inp = map(str.strip, list(open(f))[1:])

def solve(B, M):
    mat = [''.join('01'[j > i] for j in range(B)) for i in range(1,B)]
    ma = 2**(B-2)
    if M > ma:
        return 'IMPOSSIBLE'
    elif M == ma:
        return 'POSSIBLE\n0' + '1'*(B-1) + '\n' + '\n'.join(mat)
    else:
        return 'POSSIBLE\n' + bin(M)[2:].rjust(B-1).replace(' ', '0') + '0\n' + '\n'.join(mat)


# for t, n in enumerate(inp):
    # print 'Case #%d: %s' % (t+1, solve(n))
# T = int(inp.pop(0))
t = 1
while inp:
    vals = map(int, inp.pop(0).split())
    print 'Case #%d: %s' % (t, solve(*vals))
    t += 1