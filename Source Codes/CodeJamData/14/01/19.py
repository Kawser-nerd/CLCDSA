inputFile = open('A-small-attempt0.in', 'r')
lines = inputFile.readlines()
inputFile.close()

outputFile = open('A-small-attempt0.out', 'w')

numTests = int(lines[0])


currLine = 1
for i in range(1, numTests+1):
    firstRow = lines[int(lines[currLine])+currLine]
    currLine += 5
    secondRow = lines[int(lines[currLine])+currLine]
    currLine += 5

    firstNums = map(lambda x: int(x), firstRow.split())
    secondNums = map(lambda x: int(x), secondRow.split())
    
    intersect = [v for v in firstNums if v in secondNums]

    outputFile.write('Case #'+str(i)+': ')
    if len(intersect) == 1:
        outputFile.write(str(intersect[0])+'\n')
    elif len(intersect) == 0:
        outputFile.write('Volunteer cheated!\n')
    else:
        outputFile.write('Bad magician!\n')

outputFile.close()
    
