import sys

in_file = open('d-small.in', 'r')
out_file = open('d.out', 'w')
sys.stdin = in_file
sys.stdout = out_file

def dfs(dep, a, b, c):
    n = len(a)
    if dep == n:
        return True
    for i in xrange(n):
        if b[i]:
            continue
        flag = False
        for j in xrange(n):
            if c[j]:
                continue
            if a[i] >> j & 1:
                flag = True
                b[i] = c[j] = True
                if not dfs(dep + 1, a, b, c):
                    return False
                b[i] = c[j] = False
        if not flag:
            return False
    return True

def check(a):
    n = len(a)
    b = [False] * n
    c = [False] * n
    return dfs(0, a, b, c)

def calc(dep, a, num):
    n = len(a)
    ans = 19930131
    if dep == n:
        if check(a):
            ans = num
    else:
        for i in xrange(1 << n):
            if (a[dep] & i) != a[dep]:
                continue
            delta = bin(a[dep] ^ i).count('1')
            tmp = a[dep]
            a[dep] = i
            ans = min(ans, calc(dep + 1, a, num + delta))
            a[dep] = tmp
    return ans

T = input()
for t in xrange(T):
    n = input()
    a = [None] * n
    for i in xrange(n):
        a[i] = int(raw_input(), 2)
    print 'Case #%d: %s' % (t + 1, calc(0, a, 0))

in_file.close()
out_file.close()
