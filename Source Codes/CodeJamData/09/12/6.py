fp = open('in.txt', 'rU')
lines = (line.rstrip("\n") for line in fp.xreadlines())
C = int(lines.next())   # number of test cases
def valid_directions(y, x):
    """returns list of (new_y, new_x, crossing_time) tuples"""
    results = []
    if x % 2:   # east side of intersection
        results.append((y, x-1, 1))
        if x+1 < M*2:
            results.append((y, x+1, 2)) # street
    else:   # west side of intersection
        if x > 0:
            results.append((y, x-1, 2)) # street
        results.append((y, x+1, 1))
    if y % 2: # south side of intersection
        if y+1 < N*2:
            results.append((y+1, x, 2)) # street
        results.append((y-1, x, 1))
    else:
        results.append((y+1, x, 1))
        if y > 0:
            results.append((y-1, x, 2))
    return results

for case_index in range(C):
    N, M = [int(x) for x in lines.next().split()] # num rows, columns
    map = []    # intersections: rows have 2*M values for west, east side of each intersection
    for row in range(N):
        v = [int(x) for x in lines.next().split(' ')]
        SWT_row_data = [(v[i*3], v[i*3+1], v[i*3+2]) for i in range(M)]
        map.append(SWT_row_data)
    min_seen_time = [[None, None] * M for row in range(N*2)]
    min_seen_time[(N-1)*2+1][0] = 0
    stack = [((N-1)*2+1, 0, 0)]    # NE corner of SW intersection, time=0
    while stack:
        #print 'map', map, 'stack', stack
        new_stack = []
        for y, x, time in stack:
            #print y,x
            S, W, T = map[y/2][x/2]
            #print 'valid', valid_directions(y, x)
            #print 'min seen times', min_seen_time
            for new_y, new_x, min_time_offset in valid_directions(y, x):
                min_new_time = time + min_time_offset
                if min_seen_time[new_y][new_x] is None or min_seen_time[new_y][new_x] > min_new_time:
                    # possible move; calc how soon the light will allow it
                    if min_time_offset == 2:
                        ok = True
                        new_time = min_new_time
                        # street; always allowed
                    else:
                        # crossing intersection
                        cycle_time = (time - T) % (S + W)
                        if cycle_time < 0:
                            cycle_time += S + W
                            # north-south crossing
                        if new_y != y:
                            if cycle_time < S:
                                wait = 0
                            else:
                                wait = (S+W) - cycle_time
                        else:
                            if cycle_time < S:
                                wait = S - cycle_time
                            else:
                                wait = 0
                        #print 'waited %d to cross to %d, %d at %d; at %d in cycle' % (wait, new_y, new_x, time, cycle_time)
                        new_time = time + wait + min_time_offset
                        ok = min_seen_time[new_y][new_x] is None or min_seen_time[new_y][new_x] > new_time
                    #print 'ok', ok
                    if ok:
                        min_seen_time[new_y][new_x] = new_time
                        new_stack.append((new_y, new_x, new_time))
            stack = new_stack
            #print 'new stack is', new_stack
    print 'Case #%d: %d' % (case_index + 1, min_seen_time[0][(M-1)*2+1])
