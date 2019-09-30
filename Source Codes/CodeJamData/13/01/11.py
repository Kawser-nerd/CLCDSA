def getstr():
    res = ''
    while (len(res)==0):
        res = raw_input().strip()
    return res

def check_seq(board,seq,player):
    for i,j in seq:
        if board[i][j] not in (player, 'T'):
            return False
    return True

def check(board, player):
    S = []
    S.append( [(i,i) for i in range(4)] )
    S.append( [(3-i,i) for i in range(4)] )
    for i in range(4):
        S.append( [(i,j) for j in range(4)] )
        S.append( [(j,i) for j in range(4)] )

    for seq in S:
        if check_seq(board,seq,player):
            return True
    return False

def get_state(board):
    for player in ('X', 'O'):
        if check(board, player):
            return player + ' won'

    flat = reduce(lambda x,y: x+y, board, '')
    if flat.find('.')!=-1:
        return 'Game has not completed'
    return 'Draw'

t = input()
for testc in range(1,t+1):
    print 'Case #%d:' % testc,
    P = [getstr() for i in range(4)]
    print get_state(P)
