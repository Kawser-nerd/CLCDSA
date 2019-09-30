# Special case for small (no mirrors)

# This has become a monster O.o

inputF = open('C-small-attempt0.in', 'r')
output = open('C-small-attempt0.out', 'w')


numCases = int(inputF.readline())

def checkConfig(houseConfig):
    # For each generator, check for collisions
    r = len(houseConfig)
    c = len(houseConfig[0])
    locks = [['.']*c for i in range(r)]
    for i in range(r):
        for j in range(c):
            if houseConfig[i][j] == '-' or houseConfig[i][j] == '|':
                horizontalCollide = False
                for k in range(j-1, -1, -1):
                    char = houseConfig[i][k]
                    if char == '#':
                        break
                    elif char == '|' or char == '-':
                        horizontalCollide = True
                        break
                for k in range(j+1, c):
                    char = houseConfig[i][k]
                    if char == '#':
                        break
                    elif char == '|' or char == '-':
                        horizontalCollide = True
                        break
                verticalCollide = False
                for k in range(i-1, -1, -1):
                    char = houseConfig[k][j]
                    if char == '#':
                        break
                    elif char == '|' or char == '-':
                        verticalCollide = True
                        break
                for k in range(i+1, r):
                    char = houseConfig[k][j]
                    if char == '#':
                        break
                    elif char == '|' or char == '-':
                        verticalCollide = True
                        break
                if horizontalCollide and verticalCollide:
                    return False
                elif horizontalCollide:
                    locks[i][j] = '|'
                elif verticalCollide:
                    locks[i][j] = '-'
    
    # Update coverage based on locked beams
    for i in range(r):
        for j in range(c):
            if ((houseConfig[i][j] == '-' or houseConfig[i][j] == '|')
                and locks[i][j] != '.'):
                #print houseConfig, locks
                houseConfig[i][j] = locks[i][j]
                if locks[i][j] == '-':
                    for k in range(j-1, -1, -1):
                        char = houseConfig[i][k]
                        if char == '#':
                            break
                        elif char == '.':
                            houseConfig[i][k] = 'C'
                    for k in range(j+1, c):
                        char = houseConfig[i][k]
                        if char == '#':
                            break
                        elif char == '.':
                            houseConfig[i][k] = 'C'
                else:
                    for k in range(i-1, -1, -1):
                        char = houseConfig[k][j]
                        if char == '#':
                            break
                        elif char == '.':
                            houseConfig[k][j] = 'C'
                    for k in range(i+1, r):
                        char = houseConfig[k][j]
                        if char == '#':
                            break
                        elif char == '.':
                            houseConfig[k][j] = 'C'
    #print "New houseConfig:"
    #for line in houseConfig:
    #    print line
    # Know there aren't guaranteed collisions, and have locks for any required
    # orientations

    # Find squares that can only be reached by one beam
    updateMade = True
    while updateMade:
        updateMade = False
        for i in range(r):
            for j in range(c):
                if houseConfig[i][j] == '.':
                    # Find how many beams can reach it
                    beamCount = 0
                    lockLoc = (0,0)
                    for k in range(j-1, -1, -1):
                        char = houseConfig[i][k]
                        if char == '#':
                            break
                        elif (char == '|' or char == '-') and locks[i][k] == '.':
                            beamCount += 1
                            lockLoc = (i,k,'-')
                            break
                    for k in range(j+1, c):
                        char = houseConfig[i][k]
                        if char == '#':
                            break
                        elif (char == '|' or char == '-') and locks[i][k] == '.':
                            beamCount += 1
                            lockLoc = (i,k,'-')
                            break
                    for k in range(i-1, -1, -1):
                        char = houseConfig[k][j]
                        if char == '#':
                            break
                        elif (char == '|' or char == '-') and locks[k][j] == '.':
                            beamCount += 1
                            lockLoc = (k,j,'|')
                            break
                    for k in range(i+1, r):
                        char = houseConfig[k][j]
                        if char == '#':
                            break
                        elif (char == '|' or char == '-') and locks[k][j] == '.':
                            beamCount += 1
                            lockLoc = (k,j,'|')
                            break
                    if beamCount == 0:
                        return False
                    elif beamCount == 1:
                        # Lock the beam in place, and update its beamu
                        updateMade = True
                        a = lockLoc[0]
                        b = lockLoc[1]
                        locks[a][b] = lockLoc[2]
                        houseConfig[a][b] = lockLoc[2]
                        if locks[a][b] == '-':
                            for k in range(b-1, -1, -1):
                                char = houseConfig[a][k]
                                if char == '#':
                                    break
                                elif char == '.':
                                    houseConfig[a][k] = 'C'
                            for k in range(b+1, c):
                                char = houseConfig[a][k]
                                if char == '#':
                                    break
                                elif char == '.':
                                    houseConfig[a][k] = 'C'
                        else:
                            for k in range(a-1, -1, -1):
                                char = houseConfig[k][b]
                                if char == '#':
                                    break
                                elif char == '.':
                                    houseConfig[k][b] = 'C'
                            for k in range(a+1, r):
                                char = houseConfig[k][b]
                                if char == '#':
                                    break
                                elif char == '.':
                                    houseConfig[k][b] = 'C'
    for i in range(r):
        for j in range(c):
            if houseConfig[i][j] == 'C':
                houseConfig[i][j] = '.'
            elif ((houseConfig[i][j] == '-' or houseConfig[i][j] == '|') and
                  locks[i][j] == '.'):
                houseConfig[i][j] = '-'

    s = ''
    for i in range(r):
        for j in range(c):
            s += houseConfig[i][j]
        s += '\n'
    return s
                        
        

for i in range(numCases):
    r, c = inputF.readline().split()
    ticketCustomerPairs = []
    houseConfig = []
    for j in range(int(r)):
        line = inputF.readline().strip()
        houseConfig += [list(line)]
    s = checkConfig(houseConfig)

    if not s:
        output.write('Case #' + str(i+1) + ': IMPOSSIBLE\n')
    else:
        output.write('Case #' + str(i+1) + ': POSSIBLE\n')
        output.write(s)
inputF.close()
output.close()
