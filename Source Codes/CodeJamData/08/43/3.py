inFile = open("C-large.in", "r")
outFile = open("C-large-out.out", "w")

cases = int(inFile.readline())

for caseNum in range(1, cases+1):
    
    shipCount = int(inFile.readline())

    shipList = []
    
    for i in range(shipCount):
        ship = inFile.readline().rstrip()
        ship = ship.split(" ")
        ship = map(float, ship)
        shipList.append(ship)

##    print shipList

    maxPower = 0.0

    for i in range(shipCount):
        for j in range(i+1, shipCount):
            taxiDist = abs(shipList[i][0] - shipList[j][0]) + abs(shipList[i][1] - shipList[j][1]) + abs(shipList[i][2] - shipList[j][2])
            powerSum = shipList[i][3] + shipList[j][3]
            power = taxiDist / powerSum
            if power > maxPower:
                maxPower = power

    
##    print maxPower

    outputString = "Case #" + str(caseNum) + ": " + str(maxPower) + "\n"
    print outputString.rstrip()

    outFile.write(outputString)

    
        




inFile.close()
outFile.close()
