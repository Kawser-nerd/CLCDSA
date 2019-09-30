import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        W, H, B = map(int, f.readline().split())

        buildings = []
        for i in xrange(B):
            buildings.append(map(int, f.readline().split()))

        grid = [[1] * H for i in xrange(W)]

        for x0, y0, x1, y1 in buildings:
            for x in xrange(x0, x1+1):
                for y in xrange(y0, y1+1):
                    grid[x][y] = 0

        r = 0
        for sx in xrange(W):
            if grid[sx][0] == 0:
                continue

            cx, cy = sx, 0
            dx, dy = 0, 1

            visited = []
            while True:
                # print "at", cx, cy

                visited.append((cx, cy))

                if cy == H-1:
                    for x, y in visited:
                        grid[x][y] = 0
                    r += 1
                    # print "made it!"
                    break

                dx, dy = -dy, dx
                failed = False
                while True:
                    nx, ny = cx + dx, cy + dy
                    if nx >= 0 and nx < W and ny >= 0 and ny < H and grid[nx][ny]:
                        cx, cy = nx, ny
                        break
                    else:
                        if (cx, cy) == (sx, 0) and (dx, dy) == (0, -1):
                            failed = True
                            break

                        dx, dy = dy, -dx

                if failed:
                    for x, y in visited:
                        grid[x][y] = 0
                    # print "failed"
                    break

                # print "moved", dx, dy

        print "Case #%d: %d" % (_T+1, r)
