def ok(x, r, c):
    if r<c:
        r, c = c, r
    if x>=7:
        return False
    if x==1:
        return True
    if (r*c)%x!=0:
        return False
    if r<x:
        return False
    if c<(x+1)/2:
        return False
    if x==2:
        return True
    if x==3:
        return True
    if x==4:
        if c==2:
            return False
        return True
    if x==5:
        if (r, c)==(5, 3):
            return False
        return True
    if x==6:
        if c==3:
            return False
        return True

tnum = int(raw_input())
for test in range(tnum):
    x, r, c = [int(x) for x in raw_input().split()]
    print 'Case #{}: {}'.format(test+1, 'GABRIEL' if ok(x, r, c) else 'RICHARD')


