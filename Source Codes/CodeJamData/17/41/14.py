inputF = open('A-large.in', 'r')
output = open('A-large.out', 'w')


numCases = int(inputF.readline())

def getFreshGroups(groups, p):
    count = 0
    groups = [i%p for i in groups]
    count += groups.count(0)
    groups = [g for g in groups if g != 0]
    if p == 2 and len(groups) > 0:
        count += (len(groups)+1)/2
    elif p == 3 and len(groups) > 0:
        minMod = min(groups.count(1), groups.count(2))
        count += minMod
        remaining = max(groups.count(1), groups.count(2)) - min(groups.count(1), groups.count(2))
        count += (remaining+2)/3
    elif p == 4 and len(groups) > 0:
        # Add the 2s (possibly leaving an extra)
        count += (groups.count(2))/2
        extraTwo = ((groups.count(2) % 2) == 1)
        # Add the matched 1s and 3s
        minMod = min(groups.count(1), groups.count(3))
        count += minMod
        remaining = max(groups.count(1), groups.count(3)) - min(groups.count(1), groups.count(3))
        if extraTwo:
            count += 1 + (remaining+1)/4
        else:
            count += (remaining+3)/4
    return count
    

for i in range(numCases):
    n, p = inputF.readline().split()
    groups = [int(j) for j in inputF.readline().split()]
    numFresh = getFreshGroups(groups, int(p))
    
    output.write('Case #' + str(i+1) + ': ' + str(numFresh) + '\n')
inputF.close()
output.close()
