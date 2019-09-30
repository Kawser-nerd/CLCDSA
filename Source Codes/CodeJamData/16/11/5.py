task = 'A'
type = 2

if type == 0:
    inp = open('sample.in', 'r')
elif type == 1:
    inp = open('%s-small.in' % (task,))
else:
    inp = open('%s-large.in' % (task), )
outp = open('%s.out' % (task,), 'w')

T = int(inp.readline()[:-1])
for i in range(T):
    ans = ''
    st = inp.readline()[:-1]
    curmax = 0
    for c in st:
        if ord(c) >= curmax:
            ans = c + ans
            curmax = ord(c)
        else:
            ans = ans + c

    outp.write("Case #%s: %s\n" % (i + 1, ans))
