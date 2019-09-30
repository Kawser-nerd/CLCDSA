t = int(raw_input())
for case in xrange(t):
    n, k = [int(s) for s in raw_input().split()]
    print "Case #%s: %s" % (case+1,{False:"OFF",True:"ON"}[k%(1<<n)==(1<<n)-1])
