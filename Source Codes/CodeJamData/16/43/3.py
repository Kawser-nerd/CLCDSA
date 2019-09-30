import sys

def getWords():
    return sys.stdin.readline().strip().split()

def getInts():
    return [int(i) for i in getWords()]

def getInt():
	i = getInts()
	assert len(i)==1
	return i[0]

#sys.stdin = open('C.in')

def toPos(j):
    i=j-1
    if i<C:
        return ((0, 2*i+1), (1, 0))
    i-=C
    if i<R:
        return ((2*i+1, 2*C), (0, -1))
    i-=R
    if i<C:
        return ((2*R, 2*C-1-2*i), (-1, 0))
    i-=C
    return ((2*R-2*i-1, 0), (0,1))

def onEdge(pos):
    return pos[0]==0 or pos[0]==2*R or pos[1]==0 or pos[1]==2*C

def printBoard():
    for row in board:
        print ''.join(row)

T = getInt()
for caseNo in xrange(1,T+1):
    R, C = getInts()
    pairs = getInts()
    
    pair = dict()
    for i in range(R+C):
        a, b = pairs[2*i:2*i+2]
        pair[a] = b
        pair[b] = a
    
    board = [ ['?' for c in xrange(C)] for r in xrange(R) ]
    openBrackets = set()

    good = True
    for i in range(1,2*(R+C)+1):
        if pair[i] not in openBrackets:
            openBrackets.add(i)
            continue

        j = pair[i]
        openBrackets.remove(j)
        #print j

        pos0, dr = toPos(j)
        pos = pos0
        dest = toPos(i)[0]
        while pos != dest:
            #print pos, dr
            if pos != pos0 and onEdge(pos):
                good=False
                break

            r, c = (pos[0]+dr[0])//2, (pos[1]+dr[1])//2
            if board[r][c] == '?':
                board[r][c] = '/' if (dr[0] == 0) else '\\' #turn left if possible

            if board[r][c] == '/':
                dr_new = (-dr[1], -dr[0])
            else:
                dr_new = (dr[1], dr[0])

            pos = tuple( p+d+d1 for (p, d, d1) in zip(pos, dr, dr_new))
            dr = dr_new
            #printBoard()
        
        if not good:
            break
    
    for r in range(R):
        for c in range(C):
            if board[r][c]=='?':
                board[r][c]='/'
    
    print "Case #%d: "%(caseNo, )
    if good:
        printBoard()
    else:
        print "IMPOSSIBLE"

