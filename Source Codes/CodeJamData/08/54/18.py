def waysToReachExit(r,c):
    ##
    ##print "Checking ",r,c
    if c == W and r == H:
        ##print "Hit Exit!"
        return 1

    if c > W or r > H:
        ##print r, c, " is out of bounds"
        return 0
        
    
    isRock = False
    for rock in rocks:
        if rock[0] == r and rock[1] == c:
            isRock = True
            ##print "Rock Collision"
    if isRock == True:
        return 0

    if squareData.has_key((r,c)):
        result = squareData[(r,c)]
        ##print "SquareData", r, c, "is ", result
        return result

    else:
        result = waysToReachExit(r+1, c+2) + waysToReachExit(r+2,c+1)
        squareData[r,c] = result
        return result

    
    




inFile = open("D-small-attempt0.in", "r")
outFile = open("D-small-out.out", "w")

cases = int(inFile.readline())

for caseNum in range(1, cases+1):

    params = inFile.readline().rstrip()
    params = params.split(" ")
    params = map(int, params)

    H = params[0]
    W = params[1]
    R = params[2]

    rocks = []
    for i in range(R):
        rock = inFile.readline().rstrip()
        rock = rock.split(" ")
        rock = map(int, rock)
        rocks.append(rock)

    ##print H, W, rocks

    squareData = {}
    
    answer = waysToReachExit(1,1)
    ## answer
    answer = answer % 10007

    outString = "Case #" + str(caseNum) + ": " + str(answer) + "\n"
    print outString.rstrip()

    outFile.write(outString)

inFile.close()
outFile.close()
