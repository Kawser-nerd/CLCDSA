tnum = int(raw_input())
for tcou in range(tnum):
    n = int(raw_input())
    c = [int(x) for x in raw_input().split()]
    c = {chr(ord('A')+i): x for i, x in enumerate(c)}
    print "Case #{}:".format(tcou+1),
    while True:
        for p in c.keys():
            if c[p]==0:
                del c[p]
        if len(c)==0:
            break
        if max(c.values())>sum(c.values()):
            raise Exception("What?")
        if len(c)==2:
            print "{}{}".format(*c.keys()),
            for x in c:
                c[x]-=1
            continue
        x = max([(y, x) for x, y in c.iteritems()])[1]
        print "{}".format(x),
        c[x]-=1
        continue
    print
