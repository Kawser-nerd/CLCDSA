with open('input1.txt', 'r') as fin:
    with open('output1.txt', 'w') as fout:
        numcases = int(fin.readline())
        for i in range(1,numcases+1):
            orange = [1,0] #pos, steps
            blue = [1,0]
            
            robotmap = {'O':orange, 'B':blue}
            notrobotmap = {'O':blue, 'B':orange}
            line = fin.readline().split()
            for j in range(1, len(line), 2):
                r = robotmap[line[j]]
                notr = notrobotmap[line[j]]
                target = int(line[j+1])
                r[1] += abs(target-r[0])+1
                if (r[1] <= notr[1]):
                    r[1] = notr[1] + 1
                r[0] = target

            fout.write("Case #"+str(i)+": "+str(max((orange[1],blue[1])))+'\n')
