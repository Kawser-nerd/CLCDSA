
import string

inFile = open("input2.txt", "r")
outFile = open("output2.txt", "w")

   
def solve1(D, L):
    res = []
    for ll in L:
        dd = {}
        for di in range(len(D)):
            gus =tuple(['_']* len(D[di]))
            if gus in dd:
                dd[gus].append(di)
            else:
                dd[gus]=[di]
        #print (dd)
        res =res +[ ''.join(solve1a(D, dd, ll))]
        #print (res)
    return res

def solve1a(D, dd, ll):
    cost = [0 for i in range(len(D))]
    while len(ll) > 0:
        c = ll.pop(0)
        newDD = {}
        for gus in dd:
            matchCnt = 0
            unmatch=[]
            for di in dd[gus]:
                if c in D[di]:
                    matchCnt += 1
                    newGus = list(gus)
                    for i in range(len(gus)):
                        if c == D[di][i]:
                            newGus[i] = c
                    newGus = tuple(newGus)
                    if newGus in newDD:
                        newDD[newGus].append(di)
                    else:
                        newDD[newGus] = [di]
                else:
                    unmatch.append(di)
                    if gus in newDD:
                        newDD[gus].append(di)
                    else:
                        newDD[gus] = [di]
            if matchCnt < len(dd[gus]) and matchCnt > 0:
                for di in unmatch:
                    cost[di] += 1
        dd = newDD
        if len(dd)==len(D):
            break;
        #print (newDD)
        #print (cost)
    #print (cost)
    maxx = max(cost)
    for i in range(len(cost)):
        if cost[i]==maxx:        
            return D[i]

N = int(inFile.readline())
cnt = 0
for case in range(1, N + 1):
    cnt += 1
    D = []
    L = []
    llLine = inFile.readline().split()
    for i in range(int(llLine[0])):
        D += [list(inFile.readline().strip())]
    for i in range(int(llLine[1])):
        L += [list(inFile.readline().strip())]

    #print (D, L)
    result = solve1(D, L)
    
    resStr = "Case #" + str(cnt) + ":"
    for w in result:
        resStr += " " +w
    resStr = resStr + "\n"
    print (resStr)
    outFile.write(resStr)
    
