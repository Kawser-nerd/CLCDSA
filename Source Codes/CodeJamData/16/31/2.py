#!/usr/bin/python

f = 'a-sample.in'
f = 'A-small-attempt0.in'
f = 'A-large.in'

inp = map(str.strip, list(open(f))[1:])

let = lambda n:chr(ord('A') + n - 1)

def solve(vals):
    vals = zip(map(int, vals), range(1, len(vals)+1))
    vals.sort(reverse=True)
    evac = (vals[0][0] - vals[1][0]) * [let(vals[0][1])]
    evac += [let(p) for x, p in vals[2:] for i in range(x)]
    evac += [let(vals[0][1])+let(vals[1][1])] * vals[1][0]
    # print evac
    return ' '.join(evac)


# for t, n in enumerate(inp):
    # print 'Case #%d: %s' % (t+1, solve(n))
# T = int(inp.pop(0))
t = 1
while inp:
    N = int(inp.pop(0))
    vals = tuple(inp.pop(0).split())
    print 'Case #%d: %s' % (t, solve(vals))
    t += 1