n = int(raw_input())
for v in range(n):
    board = []
    inpline = raw_input().split(' ')
    m = int(inpline[0])
    n = int(inpline[1])
    [board.append([int(x) for x in raw_input().split(' ')]) for i in range(m)]

    bs = sorted([(i,j) for i in range(m) for j in range(n)],
                key=lambda (i,j):board[i][j])
    # print bs

    good = True
    for (i,j) in bs:
        if board[i][j]=='X': continue

        if all(board[i2][j] in [board[i][j], 'X'] for i2 in range(m)):
            for i2 in range(m): board[i2][j] = 'X'
        elif all(board[i][j2] in [board[i][j], 'X'] for j2 in range(n)):
            for j2 in range(n): board[i][j2] = 'X'
        else:
            good=False
            break
    print 'Case #%d: %s'%(v+1, 'YES' if good else 'NO')
    
