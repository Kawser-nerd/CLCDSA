import sys
rl = lambda: sys.stdin.readline().strip()

def shrink(board):
    minx, maxx = len(board[0]), 0
    miny, maxy = len(board), 0
    for y in range(len(board)):
        for x in range(len(board[y])):
            if board[y][x]:
                minx = min(minx, x)
                miny = min(miny, y)
                maxx = max(maxx, x)
                maxy = max(maxy, y)
    return [row[minx:maxx+1] for row in board[miny:maxy+1]]

def generate(board):
    h, w = len(board), len(board[0])
    next = [[0] * (w+1) for i in range(h+1)]
    lives = False
    for i in range(h+1):
        for j in range(w+1):
            if i < h and j < w and board[i][j] == 1:
                if ((i == 0 or board[i-1][j] == 0) and
                    (j == 0 or board[i][j-1] == 0)):
                    pass
                else:
                    next[i][j] = 1
                    lives = True
            else:
                if (i > 0 and j < w and board[i-1][j] == 1 and
                    j > 0 and i < h and board[i][j-1] == 1):
                    next[i][j] = 1
                    lives = True

    return shrink(next), lives

t = int(rl())
for cc in range(t):
    board = [[0] * 200 for i in range(200)]
    r = int(rl())
    for i in range(r):
        x1, y1, x2, y2 = map(int, rl().split())
        for x in range(x1,x2+1):
            for y in range(y1,y2+1):
                board[y][x] = 1
    board = shrink(board)
    seconds = 0
    while True:
        #print "\n".join([" ".join(map(str, e)) for e in board])
        #print
        nextboard, lives = generate(board)
        seconds += 1
        #if seconds == 10: break
        board = nextboard
        if not lives:
            break
    print "Case #%d: %d" % (cc+1, seconds)
