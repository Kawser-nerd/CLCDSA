import sys, collections


infile = sys.stdin

def get_time(segments, S, R, running_time):
    # run on slowest segments
    segments = collections.deque(sorted(segments, key=lambda s: s[1]))
    t = 0
    while segments:
        sdist, sspeed = segments.popleft()
        if running_time>0:
            rt = sdist / (sspeed+R)
            if rt <= running_time:
                # run for entire segment
                running_time -= rt
                t += rt
            else:
                # run as long as possible
                remaining = sdist - (running_time*(R+sspeed))
                t += running_time + (remaining/(S+sspeed))
                running_time = 0
        else:
            t += (sdist/(S+sspeed))
    return t
    

T = int(infile.readline())
for i in xrange(T):
    X, S, R, t, N = map(int, infile.readline().split())
    segments = []
    wdist = 0
    for j in xrange(N):
        B, E, w = map(float, infile.readline().split())
        segments.append((E-B, w))
        wdist += E-B
    # extra segment for no walkway
    segments.append((X-wdist, 0))
    result = get_time(segments, float(S), float(R), float(t))

    print("Case #%d: %f" % (i+1, result))
