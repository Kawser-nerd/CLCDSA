from itertools import count

def board(rows):
    n = len(rows[0]) * 4
    return [map(int, '{0:0{1}b}'.format(int(row, 16), n)) for row in rows]

def squares(board):
    m, n = len(board), len(board[0])
    #sq = {}
    for r in xrange(m):
        for c in xrange(n):
            if board[r][c] == 2: continue
            ns = findsquare(board, r, c)
            yield ns, -r, -c
            #fill(board, r, c, ns)
            #sq[ns] = sq.get(ns, 0) + 1
    #return sq

def solve(board):
    result = {}
    m, n = len(board), len(board[0])
    while 1:
        try:
            n, r, c = max(squares(board))
        except ValueError:
            return result
        result[n] = result.get(n, 0) + 1
        fill(board, -r, -c, n)

def fill(board, r, c, n):
    for i in xrange(r, r+n):
        for j in xrange(c, c+n):
            board[i][j] = 2

def findsquare(board, r, c):
    x = board[r][c]
    try:
        for s in count(1):
            for j in range(c, c+s+1):
                x = 1 - x
                if board[r+s][j] != x:
                    return s
            for i in range(r+s-1, r-1, -1):
                x = 1 - x
                if board[i][c+s] != x:
                    return s
    except IndexError:
        return s

if __name__ == '__main__':
    import sys
    rl = iter(sys.stdin).next
    for case in range(1, int(rl())+1):
        M,N = map(int, rl().split())
        lines = [rl().strip() for _ in range(M)]
        b = board(lines)
        sq = solve(b)
        print 'Case #%d: %s' % (case, len(sq))
        for k, v in sorted(sq.items(), reverse=True):
            print k,v
