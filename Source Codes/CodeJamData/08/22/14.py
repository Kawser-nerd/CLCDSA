import psyco
psyco.full()
import sys
def readline():
    return sys.stdin.readline()

def gcd(a,b):
    while b:
        a, b = b, a % b
    return a

def factor(n):
    if n == 1:
        return [(1,1)]
    f = []
    i = 2
    result = []
    while i * i <= n:
        if n % i == 0:
            k = 0
            while n % i == 0:
                n /= i
                k += 1
            result.append((i, k))
        i += 1
    if n != 1:
        result.append((n, 1))
    return result

def set_init(A, B):
    s = {}
    for i in xrange(A, B+1):
        s[i] = -1
    return s

def find(s, a):
    root = a
    while s[root] >= 0:
        root = s[root]
    while a != root:
        lead = s[a]
        s[a] = root
        a = lead
    return root

def union(s, a, b):
    a = find(s, a)
    b = find(s, b)
    if a == b:
        return
    tmp = s[a] + s[b]
    if s[a] > s[b]:
        s[a] = b
        s[b] = tmp
    else:
        s[b] = a
        s[a] = tmp


def main():

    ncase = int(readline())
    for case in range(ncase):
        A, B, P = map(int, readline().split())

        s = set_init(A, B)

        for i in xrange(A, B+1):
            for j in xrange(i+1, B+1):
                g = gcd(i, j)
                if factor(g)[-1][0] >= P:
                    union(s, i, j)
        setcount = set()
        for i in xrange(A, B+1):
            setcount.add(find(s, i))
        ans = len(setcount)

        print 'Case #%d: %d' % (case+1, ans)

main()
