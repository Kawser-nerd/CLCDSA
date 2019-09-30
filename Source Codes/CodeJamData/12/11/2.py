with open('A-large.in', 'r') as fin:
#with open('input.txt', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for i in range(1, numcases+1):
            line = [int(j) for j in fin.readline().split()]
            charstyped = line[0]
            numchars = line[1]
            line = [float(j) for j in fin.readline().split()]

            bestcost = numchars+2

            correctprob = 1
            for idx in range(charstyped):
                correctprob = correctprob * line[idx]
                currcost = (numchars+1)*(1-correctprob) + (charstyped-idx-1) + (numchars-idx-1) + 1
                #print(str(correctprob) + " " + str(currcost))
                if currcost < bestcost:
                    bestcost = currcost
            '''
            currcost = (numchars+1)*(1-correctprob) + (numchars-charstyped)+1
            if currcost < bestcost:
                bestcost = currcost
'''
            
            
            
            fout.write("Case #")
            fout.write(str(i))
            fout.write(": ")
            fout.write(str(bestcost))
            fout.write('\n')
            print(i)
