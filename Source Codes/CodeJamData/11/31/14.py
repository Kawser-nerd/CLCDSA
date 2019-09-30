filename = "A-large.in"
outputname = filename + "out.txt"

inFile = open(filename, 'r')
outFile = open(outputname, 'w')

numCases = int(inFile.readline())

def getSolMatrix(tiles):
    solution = [[0]*C for j in range(R)]
    # 1 : /
    # 2 : \
    for j in range(R):
        for k in range(C):
            # found a red tile
            if tiles[j][k] == 1:
                if j == R-1 or k == C-1:
                    return [], False
                elif (tiles[j][k+1] == 0 or tiles[j][k+1] == 2 or
                      tiles[j+1][k] == 0 or tiles[j+1][k] == 2 or
                      tiles[j+1][k+1] == 0 or tiles[j+1][k+1] == 2):
                    return [], False
                else:
                    tiles[j][k] = 2
                    tiles[j+1][k] = 2
                    tiles[j][k+1] = 2
                    tiles[j+1][k+1] = 2
                    solution[j][k] = 1
                    solution[j+1][k] = 2
                    solution[j][k+1] = 2
                    solution[j+1][k+1] = 1
    return solution, True

for i in range(numCases):
    nextLine = inFile.readline().split()
    R = int(nextLine[0])
    C = int(nextLine[1])
    tiles = [[0]*C for j in range(R)]
    for j in range(R):
        nextLine = inFile.readline()
        for k in range(C):
            if nextLine[k] == '#':
                tiles[j][k] = 1

    solution, valid = getSolMatrix(tiles)
    outFile.write("Case #" + str(i+1) + ":\n")
    
    if not valid:
        outFile.write("Impossible\n")
    else:
        for j in range(R):
            for k in range(C):
                if solution[j][k] == 0:
                    outFile.write('.')
                elif solution[j][k] == 1:
                    outFile.write('/')
                elif solution[j][k] == 2:
                    outFile.write('\\')
            outFile.write('\n')
            

inFile.close()
outFile.close()
