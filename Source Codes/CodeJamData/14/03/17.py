inputFile = open('C-large.in', 'r')
lines = inputFile.readlines()
inputFile.close()

outputFile = open('C-large.out', 'w')

numTests = int(lines[0])

for i in range(1, numTests+1):
    [r, c, m] = map(lambda x: int(x), lines[i].split())

    openCells = r*c - m

    works = False
    matrix = [['*']*c for j in range(r)]
    # Try case analysis first, see if my knowledge of minesweeper can cover everything
    # This is getting painful :(
    if r >= 3 and c >= 3:
        order = [(0,0), (0,1), (1,0), (1,1), (0,2), (1,2),
                 (2,0), (2,1)]
        if openCells == 1 or openCells == 4 or openCells == 6:
            works = True
            for (x,y) in order[:openCells]:
                matrix[x][y] = '.'
            matrix[0][0] = 'c'
            
        elif openCells >= 8:
            works = True
            filledRows = openCells / c
            if filledRows >= 2:
                if filledRows == r:
                    matrix = [['.']*c for j in range(r)]
                    matrix[0][0] = 'c'
                else:
                    remainder = openCells%c
                    if not remainder == 1:
                        for j in range(filledRows):
                            matrix[j] = ['.']*c
                        matrix[filledRows] = ['.']*remainder + ['*'] * (c-remainder)
                    elif filledRows > 2:
                        for j in range(filledRows-1):
                            matrix[j] = ['.']*c
                        matrix[filledRows-1] = ['.']*(c-1) + ['*']
                        matrix[filledRows] = ['.', '.'] + ['*']*(c-2)
                    else:
                        matrix[0] = ['.']*(c-1) + ['*']                        
                        matrix[1] = ['.']*(c-1) + ['*']
                        matrix[2] = ['.', '.', '.'] + ['*']*(c-3)
                    matrix[0][0] = 'c'
                
            else:
                for (x,y) in order:
                    matrix[x][y] = '.'
                remainingOpen = openCells - 8
                if remainingOpen % 2 == 0:
                    for j in range(remainingOpen/2):
                        matrix[0][j+3] = '.'
                        matrix[1][j+3] = '.'
                else:
                    matrix[2][2] = '.'
                    remainingOpen -= 1
                    for j in range(remainingOpen/2):
                        matrix[0][j+3] = '.'
                        matrix[1][j+3] = '.'
                matrix[0][0] = 'c'

    elif r == 1:
        works = True
        matrix[0] = ['.']*(c-m) + ['*']*m
        matrix[0][0] = 'c'
    elif c == 1:
        works = True
        for j in range(r-m):
            matrix[j][0] = '.'
        matrix[0][0] = 'c'

    #Only cases left are one or both dimensions being two
    elif r == 2 and c == 2:
        if m == 3:
            works = True
            matrix[0][0] = 'c'
        elif m == 0:
            works = True
            matrix = [['c', '.'], ['.', '.']]
    elif r == 2:
        if m % 2 == 0 and r*c-m > 2:
            works = True
            matrix[0] = ['.']*(c-m/2) + ['*']*(m/2)
            matrix[1] = ['.']*(c-m/2) + ['*']*(m/2)
            matrix[0][0] = 'c'
        elif r*c-m == 1:
            works = True
            matrix[0][0] = 'c'
    elif c == 2:
        if m % 2 == 0 and r*c-m > 2:
            works = True
            for j in range((r*c-m)/2):
                matrix[j] = ['.', '.']
            matrix[0][0] = 'c'
        elif r*c-m == 1:
            works = True
            matrix[0][0] = 'c'
    

    outputFile.write('Case #'+str(i)+':\n')
    '''if len(matrix) != r:
        print i, matrix
    count = 0
    for j in range(len(matrix)):
        for k in range(len(matrix[j])):
            if matrix[j][k] == '*':
                count += 1
    if count != m:
        print i, matrix'''
    if not works:
        outputFile.write('Impossible\n')
    else:
        for x in range(len(matrix)):
            for y in range(len(matrix[0])):
                outputFile.write(matrix[x][y])
            outputFile.write('\n')
outputFile.close()
            
