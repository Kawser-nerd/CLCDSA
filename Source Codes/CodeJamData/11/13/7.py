
#name = "q2"
name = "C-small-attempt3"
f_in = open(name + '.in',"r")
f_out = open(name + '.out','w')

def findTurn(myc):
        for i in range(len(myc)):
                if (MYCARDS[myc[i]][2]>0):
                        return i
        return -1

def findmax(myc):
        j = 0
        m = MYCARDS[myc[i]][1]
        for i in range(1,len(myc)):
                if (MYCARDS[myc[i]][1]>m):
                        j = i
                        m = MYCARDS[myc[i]][1]
        return j

def inBetter(myc,i):
        c1 = MYCARDS[myc[i]]
        for j in range(len(myc)):
                c2 = MYCARDS[myc[j]]
                if(c1[0] <= c2[0] and c1[1] < c2[1]):
                        return True
                if(c1[0] < c2[0] and c1[1] <= c2[1]):
                        return True
                if(c1[0] == c2[0] and c1[1] == c2[1] and i > j):
                        return True
        return False

def getScore(myc,d,t,score,dic):
        #print (myc,d,t,score,dic)
        if(t <= 0 or len(myc) == 0):
                return score
        temp = myc,d,t
        if(temp in dic):
                return dic[temp]

        j = findTurn(myc)
        socres = []
        if(j != -1):
                c = MYCARDS[myc[j]]
                ca = min(c[0],N+M - d)
                add = tuple([x for x in range(d,d+ca)])
                socres.append(getScore(myc[:j] + myc[j+1:]+add,d+ca,min(t-1+c[2],N+M - d + len(myc) - 1),score+c[1],dic))  
        else:
                tc = [x for x in range(len(myc)) if not inBetter(myc,x)]
                for i in tc:
                        c = MYCARDS[myc[i]]
                        ca = min(c[0],N+M - d)
                        add = tuple([x for x in range(d,d+ca)])
                        socres.append(getScore(myc[:i] + myc[i+1:]+add,d+ca,min(t-1+c[2],N+M - d + len(myc) - 1),score+c[1],dic))
        #print(socres)
        ret  = max(socres)
        dic[temp] = ret
        return ret

T  =  int(f_in.readline())    
for i in range(T):
        print(i)
        N = int(f_in.readline())
        MYCARDS = []
        for j in range(N):
                MYCARDS.append([int(x) for x in (f_in.readline().split())])

        M = int(f_in.readline())
        for j in range(M):
                MYCARDS.append([int(x) for x in (f_in.readline().split())])

        cards = [x for x in range(N)]
                    
        f_out.write("Case #" +str(i+1) + ": " +str(getScore(tuple(cards),N,1,0,{}))+"\n")



                
f_in.close()
f_out.close()
