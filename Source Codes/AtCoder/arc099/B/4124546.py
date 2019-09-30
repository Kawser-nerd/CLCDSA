K = int(open(0).read())

def f(n):
    n += 1
    d = 1
    c = sum(map(int, str(n)))
    p = n; q = c
    while d < n:
        b = (n // d) % 10
        n += (9 - b) * d
        c += 9 - b
        if p*c > n*q:
            p = n
            q = c
        d *= 10
    return p

ans = []
n = 0
for i in range(K):
    n = f(n)
    ans.append("%d\n" % n)
open(1, 'w').writelines(ans)