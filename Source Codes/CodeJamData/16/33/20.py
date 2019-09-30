import itertools

tnum = int(raw_input())
for tcou in range(tnum):
    a, b, c, k = [int(x) for x in raw_input().split()]
    a, b, c = sorted([a, b, c])
    if k>c:
        k = c
    print "Case #{}: {}".format(tcou+1, a*b*k)
    for ia, ib, ic in itertools.product(range(a), range(b), range(c)):
        if (ia+ib+ic)%c<k:
            print ia+1, ib+1, ic+1
