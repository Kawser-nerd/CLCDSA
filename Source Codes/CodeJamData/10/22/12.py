fin = open('in', 'r')
test_count = int(fin.readline().rstrip())
for c in xrange(test_count):
    n, k, b, t = [int(x) for x in fin.readline().rstrip().split()]
    positions = [int(x) for x in fin.readline().rstrip().split()]
    speeds = [int(x) for x in fin.readline().rstrip().split()]
    
    positions.reverse()
    speeds.reverse()
    
    fast_chicks = 0
    slow_chicks = 0
    needed_swaps = 0
    for i in xrange(n):
        if positions[i] + speeds[i]*t >= b:
            fast_chicks += 1
            needed_swaps += slow_chicks
        else:
            slow_chicks += 1
            
        if fast_chicks == k:
            break
    
    if fast_chicks < k:
        print 'Case #%d: IMPOSSIBLE' % (c+1)
    else:
        print 'Case #%d: %d' % (c+1, needed_swaps)
