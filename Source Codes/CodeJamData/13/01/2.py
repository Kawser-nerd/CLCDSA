n = int(raw_input())
for v in range(n):
    board = []
    [board.append(raw_input().strip()) for i in range(4)]
    raw_input()

    isfull = all(board[i][j]!='.' for i in range(4) for j in range(4))

    lines = [[(i,j) for j in range(4)] for i in range(4)]
    lines += [[(i,j) for i in range(4)] for j in range(4)]
    lines.append([(i,i) for i in range(4)])
    lines.append([(i,3-i) for i in range(4)])

    owin = False
    xwin = False
    for l in lines:
        if all(board[p[0]][p[1]] in ['O','T'] for p in l):
            owin = True
        if all(board[p[0]][p[1]] in ['X','T'] for p in l):
            xwin = True
    if owin:
        print 'Case #%d: O won'%(v+1)
    elif xwin:
        print 'Case #%d: X won'%(v+1)
    elif isfull:
        print 'Case #%d: Draw'%(v+1)
    else:
        print 'Case #%d: Game has not completed'%(v+1)
