import sys
rl = lambda: sys.stdin.readline().strip()

t = int(rl())
for cc in range(t):
    chicks, deliver, barn, time_limit = map(int, rl().split())
    location = map(int, rl().split())
    speed = map(int, rl().split())
    ret = 0
    delivered = 0
    lagging = 0
    for i in range(chicks-1,-1,-1):
        # (barn-location[i])/speed[i] <= T
        if barn-location[i] <= time_limit*speed[i]:
            delivered += 1
            ret += lagging
            if delivered == deliver: break
        else:
            lagging += 1
    print "Case #%d:" % (cc+1),
    if delivered < deliver:
        print "IMPOSSIBLE"
    else:
        print ret

