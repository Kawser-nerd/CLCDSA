def rl():
    return map(int,raw_input().split())

def any_lose(n,p,m):
    #print "any_lose",n,p,m
    assert 1 <= p <= n
    assert 0 <= m <= n-1

    if n == 1:
        return p <= m
    if p <= n/2:
        return m <> 0 or any_lose(n/2,p,m)
    else:
        return m <> 0 and any_lose(n/2,p-n/2,(m-1)/2)

def any_win(n,p,m):
    #print "any_win",n,p,m
    assert 1 <= p <= n
    assert 0 <= m <= n-1

    if n == 1:
        return p > m
    if p <= n/2:
        return m <> n-1 and any_win(n/2,p,(m+1)/2)
    else:
        return m <> n-1 or any_win(n/2,p-n/2,m-n/2)

def go(n,p,f):
    l = 0
    r = (2**n)-1
    while l < r:
        m = (l+r+1)/2
        if f(2**n,p,m):
            l = m
        else:
            r = m-1
    assert l == r
    return l

def main():
    T, = rl();
    for t in range(1,T+1):
        n,p = rl()
        a = go(n,p,lambda n,p,m: not any_lose(n,p,m))
        b = go(n,p,any_win)
        print "Case #%d: %d %d"%(t,a,b)

main()
