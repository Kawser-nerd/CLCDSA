import sys

iFile = open(sys.argv[1],"r")

T = int(iFile.readline().strip())

for t in range(T):
    line = iFile.readline().strip().split()
    C = int(line[0])
    D = int(line[1])
    V = int(line[2])
    
    denominations = [int(x) for x in iFile.readline().strip().split()]

    denominations.append(V+1)

    covered = 0
    additions = 0
    
    for denom in denominations:
        #did we cover everything up to now ?
        while denom > covered + 1:
            additions += 1
            covered += C*(covered+1)

        covered += C*denom
            
    answer = additions

    output = str(answer) 
    
    print("Case #"+str(t+1)+": "+output)
