# May, 23, 2010
# Round 1C
# "Making Chess Boards"

from time import time
from math import log

#inpath = "C-sample.in"
#inpath = "C-large.in"
inpath = 'C-small-attempt0.in'
outpath = "C.out"

fin = open(inpath)
fout = open(outpath, 'w')

def IsWhite((bark, i, j)):
    letter = int(bark[i][j/4], 16)
    digit = 3 - j%4
    return (letter & 2**digit) != 0

def IsQuadr(bark, i, j):
    a, b, c, d = map(IsWhite, ((bark, i, j), (bark, i, j+1),
                               (bark, i+1, j), (bark, i+1, j+1)))
    return (
        (a and d and not (b or c)) or
        (b and c and not (a or d))
        )

def Cut(table, x, y):
    if x >=0 and y >= 0 and x < len(table) and y < len(table[0]):
        table[x][y] = False

def CutPart(table, n):
    n -= 1
    count = 0
    for i in range(len(table) - n + 1):
        for j in range(len(table[0]) - n + 1):
            if not all(table[x][y] for x in range(i, i+n)
                   for y in range(j, j+n)):
                continue
            count += 1
            for x in range(i-1, i+n+1):
                for y in range(j-1, j+n+1):
                    Cut(table, x, y)
    return count

def Boards(bark, M, N):
    table = list(list(IsQuadr(bark, i, j) for j in range(N-1))
                 for i in range(M-1))
    n = min(M, N)
    result = [0]
    while n > 1:
        count = CutPart(table, n)
        if count != 0:
            result[0] += 1
            result.append((n, count))
        n -= 1
    cutted = sum(x*x*y for x, y in result[1:])
    if cutted < M*N:
        result[0] += 1
        result.append((1, M*N - cutted))
    return result

timestart = time()
T = int(fin.readline())
for case in range(1, T+1):
    M, N = map(int, fin.readline().split())
    bark = list(fin.readline().strip() for i in range(M))
    assert len(bark[0]) == N/4
    result = Boards(bark, M, N)
    fout.write("Case #%d: %s\n" % (case, result[0]))
    for x, y in result[1:]:
        fout.write("%d %d\n" % (x, y))
    print case, "done"
        
fin.close()
fout.close()
print "\nTime: %.4f" % (time() - timestart)
