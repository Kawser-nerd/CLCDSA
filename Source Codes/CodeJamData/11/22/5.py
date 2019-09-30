#!/usr/bin/python

def calc(pts, min_dist):
    next_pos = -10e7
    max_delta = 0
    island_delta = 0
    for pos, count in pts:
        # print "next_pos=%d pos=%d count=%d" % (next_pos, pos, count)
        if pos > next_pos:
            # save old island
            max_delta = max(island_delta, max_delta)
            # start new island
            island_delta = (count - 1) * min_dist
            next_pos = pos + count * min_dist
            # print "new island: island_delta=%d next_pos=%d" %\
            #         (island_delta, next_pos)
        else:
            # continue island
            last_pos = next_pos + (count - 1) * min_dist
            delta = last_pos - pos
            island_delta = max(delta, island_delta)
            next_pos = last_pos + min_dist
            # print "continued island: delta=%d next_pos=%d" %\
            #         (delta, next_pos)
    # save last island
    max_delta = max(island_delta, max_delta)
    return max_delta / 2.0


if __name__ == "__main__":
    import sys
    tests = int(sys.stdin.readline())
    for t in range(tests):
        n_pts, min_dist = map(int, sys.stdin.readline().split())
        pts = []
        for i in range(n_pts):
            pos, count = map(int, sys.stdin.readline().split())
            pts.append((pos, count))
        print "Case #%d: %f" % (t + 1, calc(pts, min_dist))


