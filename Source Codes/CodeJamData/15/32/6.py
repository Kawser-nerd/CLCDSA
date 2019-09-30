import sys

iFile = open(sys.argv[1],"r")

T = int(iFile.readline().strip())

for t in range(T):
    line = iFile.readline().strip().split()
    K = int(line[0])
    L = int(line[1])
    S = int(line[2])
    
    keyboard = iFile.readline().strip()
    target = iFile.readline().strip()

    #calculate max bananas
    #see if there is self overlap
    effectiveLength = len(target)
    for strPos in range(1,len(target)):
        if target[strPos:] == target[:-strPos]:
            effectiveLength = strPos
            break

    max_bananas = 1 + int((S-len(target))/effectiveLength)

    #calculate probability for a given position
    single_prob = 1.0
    for letter in target:
        if letter in keyboard:
            single_prob *= keyboard.count(letter) / len(keyboard)
        else:
            single_prob = 0.0
            max_bananas = 0
            break
    

    #calculate total probability
    total_prob = single_prob * (S - len(target) + 1)

    answer = max_bananas - total_prob

    output = str(answer) 
    
    print("Case #"+str(t+1)+": "+output)
