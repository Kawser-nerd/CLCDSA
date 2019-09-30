#!/usr/bin/env python

import sys

def minOfThree(a,b,c):
    if (a <= b) and (a <= c):
        return a
    elif (b <= a) and (b <= c):
        return b
    else:
        return c

def maxChessboardSize(grid,used,i,j,maxRow,maxCol):
    if used[i][j]:
        return 0
    elif ( i == maxRow or j == maxCol or grid[i][j] == grid[i+1][j] or grid[i][j] == grid[i][j+1] or grid[i][j] != grid[i+1][j+1] ):
        return 1
    else:
        return 1 + minOfThree( maxChessboardSizeDown(grid,used,i+1,j,maxRow,maxCol), maxChessboardSizeRight(grid,used,i,j+1,maxRow,maxCol), maxChessboardSize(grid,used,i+1,j+1,maxRow,maxCol) ) 

def maxChessboardSizeRight(grid,used,i,j,maxRow,maxCol):
    if used[i][j]:
        return 0
    elif ( j == maxCol or grid[i][j] == grid[i][j+1] ):
        return 1
    else:
        return 1 + maxChessboardSizeRight(grid,used,i,j+1,maxRow,maxCol)

def maxChessboardSizeDown(grid,used,i,j,maxRow,maxCol):
    if used[i][j]:
        return 0
    elif ( i == maxRow or grid[i][j] == grid[i+1][j] ):
        return 1
    else:
        return 1 + maxChessboardSizeDown(grid,used,i+1,j,maxRow,maxCol) 



def main(argv):
    n = int(sys.stdin.readline())
    for i in range(1,n+1):
        line = sys.stdin.readline()
        M,N = map(int,line.split(" "))

        squares = []

        for j in range(M):
            squares.append([])
            thisRow = squares[j]
            line = sys.stdin.readline().strip()
            for hexChar in line:
                    if (hexChar == '0'):
                        thisRow.append(False)
                        thisRow.append(False)
                        thisRow.append(False)
                        thisRow.append(False)
                    if (hexChar == '1'):
                        thisRow.append(False)
                        thisRow.append(False)
                        thisRow.append(False)
                        thisRow.append(True)
                    if (hexChar == '2'):
                        thisRow.append(False)
                        thisRow.append(False)
                        thisRow.append(True)
                        thisRow.append(False)
                    if (hexChar == '3'):
                        thisRow.append(False)
                        thisRow.append(False)
                        thisRow.append(True)
                        thisRow.append(True)
                    if (hexChar == '4'):
                        thisRow.append(False)
                        thisRow.append(True)
                        thisRow.append(False)
                        thisRow.append(False)
                    if (hexChar == '5'):
                        thisRow.append(False)
                        thisRow.append(True)
                        thisRow.append(False)
                        thisRow.append(True)
                    if (hexChar == '6'):
                        thisRow.append(False)
                        thisRow.append(True)
                        thisRow.append(True)
                        thisRow.append(False)
                    if (hexChar == '7'):
                        thisRow.append(False)
                        thisRow.append(True)
                        thisRow.append(True)
                        thisRow.append(True)
                    if (hexChar == '8'):
                        thisRow.append(True)
                        thisRow.append(False)
                        thisRow.append(False)
                        thisRow.append(False)
                    if (hexChar == '9'):
                        thisRow.append(True)
                        thisRow.append(False)
                        thisRow.append(False)
                        thisRow.append(True)
                    if (hexChar == 'A'):
                        thisRow.append(True)
                        thisRow.append(False)
                        thisRow.append(True)
                        thisRow.append(False)
                    if (hexChar == 'B'):
                        thisRow.append(True)
                        thisRow.append(False)
                        thisRow.append(True)
                        thisRow.append(True)
                    if (hexChar == 'C'):
                        thisRow.append(True)
                        thisRow.append(True)
                        thisRow.append(False)
                        thisRow.append(False)
                    if (hexChar == 'D'):
                        thisRow.append(True)
                        thisRow.append(True)
                        thisRow.append(False)
                        thisRow.append(True)
                    if (hexChar == 'E'):
                        thisRow.append(True)
                        thisRow.append(True)
                        thisRow.append(True)
                        thisRow.append(False)
                    if (hexChar == 'F'):
                        thisRow.append(True)
                        thisRow.append(True)
                        thisRow.append(True)
                        thisRow.append(True)

        numSquares = M*N

        used = []
        for j in range(M):
            used.append([])
            line = used[-1]
            for k in range(N):
                line.append(False)
        numUsed = 0

        sizes = []
        numBoards = [0]

        while (numUsed < numSquares):
            currRow = 0
            currCol = 0
            maxSize = 0
            checked = []
            for j in range(M):
                for k in range(N):
                    gridSize = maxChessboardSize(squares,used,j,k,M-1,N-1)
                    if gridSize > maxSize:
                        maxSize = gridSize
                        currRow = j
                        currCol = k
                    k += gridSize - 1

            if len(sizes) == 0:
                sizes.append(maxSize)

            if len(sizes) == 0 or sizes[-1] == maxSize:
                numBoards[-1] += 1
            else:
                sizes.append(maxSize)
                numBoards.append(1)

            numUsed += maxSize * maxSize
            for j in range(currRow,currRow + maxSize):
                for k in range(currCol,currCol + maxSize):
                    used[j][k] = True

#            if numUsed > 72:
#                print used
#                print squares
#                sys.exit(0)

        print("Case #%d: %d" % (i,len(sizes)))
        for j in range(len(sizes)):
            print "%d %d" % (sizes[j],numBoards[j])

main(sys.argv)
