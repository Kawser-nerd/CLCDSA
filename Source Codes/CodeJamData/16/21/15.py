import sys

sys.setrecursionlimit(100000)

inp = sys.stdin
outp = sys.stdout

words = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

m = [(0, 'Z'), (2, 'W'), (4,'U'), (6,'X'), (7,'S'), (5, 'V'), (1,'O'), (3, 'R'), (8, 'H'), (9, 'E')
     ]

def solve():
    x = sys.stdin.readline().strip()
    f = [0]*10
    for (d, c) in m:
        cnt = x.count(c)
        f[d] += cnt
        for c2 in words[d]:
            x = x.replace(c2, '', cnt)
    assert x == ''
    for i in range(10):
        outp.write(('%d'%i)*f[i])
    print









T = int(inp.readline())
for i in range(T):
    outp.write('Case #%d: ' % (i+1))
    solve()
