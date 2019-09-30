from Queue import PriorityQueue

with open('B-large.in', 'r') as fin:
#with open('input.txt', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for i in range(1, numcases+1):
            line = [int(j) for j in fin.readline().split()]
            numlevels = line[0]

            doables = []
            levels = PriorityQueue()
            
            for j in range(numlevels):
                line = [int(k) for k in fin.readline().split()]
                levels.put((line[0], line[1])) #returns lowest

            stars = 0
            played = 0

            while True:
                while not levels.empty():
                    nextlevel = levels.get()
                    if nextlevel[0] <= stars:
                        if nextlevel[1] == None:
                            #print("replay" + str(nextlevel))
                            #this is a replay for 2nd star
                            played += 1
                            stars += 1
                        else:
                            doables.append(nextlevel[1])
                            #to sort lowest-first
                    else:
                        levels.put(nextlevel) #put it back (no peek?)
                        break
                doables.sort()
                if len(doables) == 0:
                    if not levels.empty():
                        played = -1
                    break
                else:
                    lowlevel = doables[0]
                    played += 1
                    if lowlevel <= stars:
                        stars += 2
                        doables = doables[1:]
                    else:
                        stars += 1
                        levels.put((doables[-1], None))
                        del doables[-1]

            
                
            
            
            fout.write("Case #")
            fout.write(str(i))
            fout.write(": ")
            if (played >= 0):
                fout.write(str(played))
            else:
                fout.write("Too Bad")
            fout.write('\n')
            print(i)
