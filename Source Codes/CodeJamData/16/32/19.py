tcou = int(raw_input())
for tnum in range(tcou):
    B, M = [int(x) for x in raw_input().split()]
    print "Case #{}:".format(tnum+1),
    if 2**(B-2)<M:
        print "IMPOSSIBLE"
    else:
        print "POSSIBLE"
        for i in range(B):
            S = ''.join(['0' if j<=i else '1' for j in range(B-1)])
            t = '#'
            if i==0:
                t = '1'
            elif i==B:
                t = '0'
            else:
                if (M-1)&(2**(i-1))!=0:
                    t = '1'
                else:
                    t = '0'
            print S+t
