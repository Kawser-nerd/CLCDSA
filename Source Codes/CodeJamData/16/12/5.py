task = 'B'
type = 2
from collections import Counter

if type == 0:
    inp = open('sample.in', 'r')
elif type == 1:
    inp = open('%s-small.in' % (task,))
else:
    inp = open('%s-large.in' % (task), )
outp = open('%s.out' % (task,), 'w')

T = int(inp.readline()[:-1])
for i in range(T):
    ans = []
    N = int(inp.readline()[:-1])
    c = Counter()
    for j in range(2*N-1):
        s = inp.readline()[:-1].split()
        for k in s:
            c[k] += 1

    for val in c.items():
        if val[1] % 2 == 1:
            ans.append(val[0])
    ans.sort(key=int)

    outp.write("Case #%s: %s\n" % (i + 1, " ".join(ans)))
