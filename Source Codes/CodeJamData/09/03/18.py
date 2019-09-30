from sys import stdin
from sys import stdout

pattern = 'welcome to code jam'
ip = {}
for i, c in enumerate(pattern):
    ip.setdefault(c, []).append(i)
n = len(pattern)

N = int(stdin.readline().strip())
for i in xrange(1, N + 1):
    line = stdin.readline().strip()
    ans = []
    for p, c in enumerate(line):
        val = [0] * n
        if c in ip:
            for j in ip[c]:
                if j == 0:
                    val[j] = 1
                else:
                    for k in xrange(p):
                        val[j] += ans[k][j - 1]
                    val[j] %= 10000
        ans.append(val)
    total = 0
    for val in ans:
        total += val[n - 1]
    stdout.write('Case #%d: %04d\n' % (i, total % 10000))
