import sys

iFile = open(sys.argv[1],"r")

T = int(iFile.readline().strip())

for t in range(T):
    line = iFile.readline().strip().split()
    R = int(line[0])
    C = int(line[1])
    W = int(line[2])
    
    shotsFailRows = 0
    shotsWinRow = 0
    remainingFields = C
    while remainingFields >= 2*W:
        remainingFields -= W
        shotsFailRows += 1
        shotsWinRow += 1

    shotsWinRow += min(remainingFields,W+1)
    shotsFailRows += 1

    answer = (R-1) * shotsFailRows + shotsWinRow

    output = str(answer)
    
    print("Case #"+str(t+1)+": "+output)
