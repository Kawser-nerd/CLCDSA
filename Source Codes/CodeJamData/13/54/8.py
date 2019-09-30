from sys import stdin
memo = [[-1] * (1 << n) for n in xrange(21)]
for n in xrange(21):
    memo[n][0] = 0.0
    for ss in xrange(1, 1 << n):
        if memo[n][ss] != -1:
            continue
        s = bin(ss)[2:].zfill(n)
        m = []
        for k in xrange(n):
            if ss >> k & 1:
                m.append(memo[n][ss ^ (1 << k)])
            else:
                m.append(0.0)
        m.reverse()
        d = [0.0] * n
        t = s + s
        i = n + n - 1
        while t[i] == '0':
            i -= 1
        while i >= 0:
            if t[i] == '1':
                x = m[i%n]
                d[i%n] = n + x
                j = i - 1
                while j >= 0 and t[j] == '0':
                    d[j%n] = n - (i - j) + x
                    j -= 1
                i = j
        f = sum(d) / n
        for i in xrange(n):
            memo[n][int(s, 2)] = f
            s = s[-1] + s[:-1]
def solve():
    x = stdin.readline().strip()
    n = len(x)
    t = 0
    for i in xrange(n):
        if x[i] == '.':
            t += 1 << (n - 1 - i)
    return memo[n][t]
T = int(stdin.readline())
for i in xrange(T):
    print "Case #%d: %.12f" % (i+1, solve())
