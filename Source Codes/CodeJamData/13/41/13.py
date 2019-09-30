
from collections import defaultdict

def rl():
    return map(int,raw_input().split())

def f(a,N):
    p = a.keys()
    p = sorted(p)
    v = []
    for i in p:
        v.append(a[i])

    res = 0
    n = len(p)
    while True:
        i = 0
        while i < n and v[i] == 0:
            i += 1
        if i == n:
            break

        assert v[i] > 0

        j = i
        s = 0
        mins = -1
        while j < n:
            if s + v[j] == 0:
                break
            s += v[j]
            j += 1
            if mins == -1:
                mins = s
            else:
                mins = min(s,mins)

        assert j < n

        c = mins
        v[i] -= c
        v[j] += c
        d = p[j] - p[i]
        res += c * ( d*(2*N+1-d)/2 )

    return res



def main():
    T, = rl()
    for t in range(1,T+1):
        n,m = rl()
        a = defaultdict(int)
        old_sum = 0
        for i in range(m):
            o,e,p = rl()
            a[o] += p
            a[e] -= p
            d = e-o
            old_sum += p*(d*(2*n+1-d)/2)
        new_sum = f(a,n)
        ans = old_sum - new_sum
        assert ans >= 0
        ans = ans % 1000002013
        print "Case #%d: %d"%(t,ans)

main()