i = 1
chess = {}
while i <= 512:
    res0 = 0
    res1 = 0
    for place in range(i):
        if place % 2 == 0:
            res0 += 2**place
        else:
            res1 += 2**place
    chess[i] = (res0, res1)
    i += 1

def setUsed(used, x, y, size, N):
    #print "Setting used:", used, x, y, size, N
    for row in range(y, y + size):
        used[row] = used[row] | (pow(2,int(N-x))-1 - (pow(2,int(N-x-size))-1))
    #print used

def isUsed(used, x, y, size, N):
    for row in range(y, y + size):
        if (used[row] & (pow(2,int(N-x))-1 - (pow(2,int(N-x-size))-1))) != 0:
            return True
    return False


def isChessboard(arr, used, x, y, size, N):
    if isUsed(used, x, y, size, N):
        return False
    global chess;
    nex = 2
    chessstring0 = int(chess[size][0]) << (N - x - size)
    chessstring1 = int(chess[size][1]) << (N - x - size)
    for row in range(y, y + size):
        actualstring = int(arr[row] & (pow(2,N-x)-1 - (pow(2,N-x-size)-1)))
        #print N, x, size, actualstring, chessstring0, chessstring1
        if nex != 1:
            if actualstring == chessstring0:
                nex = 1
                continue
        if nex != 0:
            if actualstring == chessstring1:
                nex = 0
                continue
        #print N, x, size, actualstring, chessstring0, chessstring1
        assert(size != 1)
        return False
    return True


infile = open("C-small.in", "r")

T = int(infile.readline().strip())

for t in range(T):
    line = infile.readline()
    M = int(line.split(' ')[0])
    N = int(line.split(' ')[1])
    arr = []
    used = []
    sizes = 0
    results = []
    for row in range(M):
        arr.append(int(infile.readline(), 16))
        used.append(int(0))
    for size in range(min(M, N),0,-1):
        counted = False
        count = 0
        lastx = N+1
        lasty = M+1
        for y in range(M - size + 1):
            for x in range(N - size + 1):
                #if (y >= lasty and y < lasty + size) and ((x >= lastx and x < lastx + size) or (x + size-1 >= lastx and x + size-1 < lastx + size)):
                #    continue
                #print "Trying", size
                if (isChessboard(arr, used, x, y, size, N)):
                    setUsed(used, x, y, size, N)
                    count += 1
                    lastx = x
                    lasty = y
                    if not counted:
                        counted = True
                        sizes += 1
        if (count > 0):
            results.append((size, count))
    print "Case #" + str(t+1) + ": " + str(sizes)
    for tup in results:
        print tup[0], tup[1]
