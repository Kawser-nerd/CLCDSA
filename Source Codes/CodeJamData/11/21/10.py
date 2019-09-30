inFile = open("A-large.in.in", 'r')
outFile = open("A.out",'w')
N = int(inFile.readline()) # num test cases

for I in range(1,N+1):
    M = int(inFile.readline()) # test case size
    grid = []
    for i in range(M):
        grid.append(list(inFile.readline()))
    # calculate winning percentages
    won = [0 for i in range(M)]
    played = [0 for i in range(M)]
    for i in range(M):
        for j in range(M):
            if grid[i][j] != '.':
                played[i] += 1
                if grid[i][j] == '1':
                    won[i] += 1
    owp = [0 for i in range(M)]
    for i in range(M):
        n = 0
        for j in range(M):
            if grid[i][j] != '.':
                owp[i] += (won[j]-int(grid[j][i]))/(played[j]-1)
                n += 1
        if n != 0: owp[i] /= n
    
    rpi = [0 for i in range(M)]
    for i in range(M):
        rpi[i] += .25*won[i]/played[i] + .5*owp[i]
        oowp = 0
        n = 0
        for j in range(M):
            if grid[i][j] != '.':
                oowp += owp[j]
                n += 1
        if n != 0: rpi[i] += .25*oowp/n
        
    outFile.write("Case #"+str(I)+":\n")
    print("Case #"+str(I)+":")
    for i in range(M):
        outFile.write(str(rpi[i])+"\n")
        print(rpi[i])
