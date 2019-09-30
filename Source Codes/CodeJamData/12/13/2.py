from Queue import PriorityQueue

def lanesearch(lane, posn):
    #sucks, can improve later
    lastidx = 0
    for i in range(len(lane)):
        if lane[i][0] < posn + 5:
            if posn < lane[i][0] + 5:
                return None
            else:
                lastidx = i
        else:
            break
    return lastidx

with open('C-small-attempt0.in', 'r') as fin:
#with open('input.txt', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for case in range(1, numcases+1):
            line = [int(j) for j in fin.readline().split()]
            numcars = line[0]

            left = []
            right = []
            for j in range(numcars):
                line = fin.readline().split()
                car = [float(line[2]), int(line[1])]
                if line[0] == 'L':
                    left.append(car)
                else:
                    right.append(car)
            

            totaltime = 0
            swapposns = set([])

            while True:
                left.sort()
                right.sort()
                #print(left)
                #print(right)
                advancetime = None
                leftcar = None
                rightcar = None
                for i in range(len(left)-1):
                    if left[i][1] > left[i+1][1]:
                        deltavel = left[i][1] - left[i+1][1]
                        deltapos = left[i+1][0] - left[i][0] - 5
                        time = deltapos / deltavel
                        if advancetime == None or time < advancetime:
                            leftcar = i
                            advancetime = time
                for i in range(len(right)-1):
                    if right[i][1] > right[i+1][1]:
                        deltavel = right[i][1] - right[i+1][1]
                        deltapos = right[i+1][0] - right[i][0] - 5
                        time = deltapos / deltavel
                        if advancetime == None or time < advancetime:
                            leftcar = None
                            rightcar = i
                            advancetime = time
                print(str(leftcar) + "," + str(rightcar) + ":"+str(advancetime))
                if (advancetime == None):
                    totaltime = None
                    break

                for i in left:
                    i[0] += advancetime*i[1]
                for i in right:
                    i[0] += advancetime*i[1]
                totaltime += advancetime

                print(left)
                print(right)
                #print("swap")

                if (advancetime > 0):
                    swapposns.clear()
                
                
                    
                if leftcar != None:
                    leftidx = leftcar
                    swapcar = left[leftcar]
                    search = None
                    if (swapcar[0] not in swapposns):
                        search = lanesearch(right, swapcar[0])
                    if search == None:
                        leftidx = leftcar+1
                        swapcar = left[leftcar+1]
                        if (swapcar[0] not in swapposns):
                            search = lanesearch(right, swapcar[0])
                        if search == None:
                            break
                        #print("left search false")
                    
                    del left[leftidx]
                    right.insert(search, swapcar)
                    swapposns.add(swapcar[0])
                else:
                    rightidx = rightcar
                    swapcar = right[rightcar]
                    search = None
                    if (swapcar[0] not in swapposns):
                        search = lanesearch(left, swapcar[0])
                    if search == None:
                        rightidx = rightcar+1
                        swapcar = right[rightcar+1]
                        if (swapcar[0] not in swapposns):
                            search = lanesearch(left, swapcar[0])
                        if search == None:
                            break
                        #print("left search false")
                    
                    del right[rightidx]
                    left.insert(search, swapcar)
                    swapposns.add(swapcar[0])
            
                
            
            
            fout.write("Case #")
            fout.write(str(case))
            fout.write(": ")
            if (totaltime != None):
                fout.write(str(totaltime))
            else:
                fout.write("Possible")
            fout.write('\n')
            print(case)
