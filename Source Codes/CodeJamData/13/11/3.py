def paint(r, n):
    return (2*(r+n)-1)*n

def ans(r, t):
    l = 0
    u = t
    while l!=u:
        m = (l+u+1)/2
        if paint(r, m)<=t:
            l=m
        else:
            u=m-1
    return l

tnum = input()
for tind in range(tnum):
    r, t = [int(x) for x in raw_input().split()]
    print "Case #%d: %d"%(tind+1, ans(r, t))
