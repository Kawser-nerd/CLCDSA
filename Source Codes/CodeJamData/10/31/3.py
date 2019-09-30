T = int(raw_input())

for t in range(1, T+1):
    N = int(raw_input())
    points = []
    for n in range(N):
        a, b = map(int, raw_input().split())
        points.append((a, b))
    points.sort()
    c = 0
    for i in range(N):
        x1, y1 = points[i]
        for j in range(i + 1, N):
            x2, y2 = points[j]
            if (x2 - x1) * (y2 - y1) < 0:
                c += 1
    print "Case #%d: %d" % (t, c)
