filename = "C-small-attempt1.in"
outputname = filename + "out.txt"

inFile = open(filename, 'r')
outFile = open(outputname, 'w')

numCases = int(inFile.readline())

for i in range(numCases):
    print i
    nextLine = inFile.readline().split()
    numPlayers = int(nextLine[0])
    low = int(nextLine[1])
    high = int(nextLine[2])

    players = []
    playerLine = inFile.readline().split()
    for j in range(numPlayers):
        players += [float(playerLine[j])]

    minFreq = min(players)
    possFreqs = [minFreq*j for j in range(1, int(high/minFreq)+1)]
    for j in range(1, int(minFreq)):
        if (minFreq/j)%1 == 0:
            possFreqs += [j]

    #print i, possFreqs
    for player in players:
        #print player, possFreqs
        j = len(possFreqs)-1
        while j >= 0:
            if (player/possFreqs[j])%1 == 0 or (possFreqs[j]/player)%1 == 0:
                j -= 1
            else:
                possFreqs.pop(j)
                j -= 1

    #print i, possFreqs
    finals = []
    for freq in possFreqs:
        if freq >= low and freq <= high:
            finals += [freq]

    finals.sort()
    if len(finals) == 0:
        outFile.write("Case #" + str(i+1) + ": NO\n")
    else:
        outFile.write("Case #" + str(i+1) + ": " + str(int(finals[0])) + "\n")

inFile.close()
outFile.close()
