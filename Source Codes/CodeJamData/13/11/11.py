def readline():
    return [int(x) for x in raw_input().split(' ')]

v = readline()[0]
for case in range(v):
    r,t = readline()
    lb=1
    ub=t
    while lb<ub:
        mb=(lb+ub+1)/2
        if 2*r*mb+2*mb*mb-mb<=t:
            lb=mb
        else:
            ub=mb-1
    print "Case #%d: %d"%(case+1,lb)
