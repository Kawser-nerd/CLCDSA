def match(a,b,letter):
    if len(a) != len(b):
        return False
    if letter==' ':
        return True
    for i in range(len(a)):
        if a[i]!=b[i]:
            if a[i]==letter or b[i]==letter:
                return False
    return True

def score(word,wMap,order):
    poss = wMap[word][" "]
    ind = 0
    s=0
    while len(poss)>1:
        char = order[ind]
        found = False
        for w in poss:
            if char in w:
                found = True
                break
        if found:
            poss = [w for w in poss if w in wMap[word][char]]
            if char not in word:
                s=s+1
        ind=ind+1
    return s

guessStr = " abcdefghijklmnopqrstuvwxyz"

def run():
    f=open("input.in")
    g=open("out.txt",'w')
    num = int(f.readline())
    for i in range(num):
        g.write("Case #%d:" % (i+1))
        [nwords,nlists]=map(int,f.readline().split())
        myDict = {}
        myList=[]
        for j in range(nwords):
            myList.append(f.readline()[:-1])
            myDict[myList[-1]]={}
        for word in myDict:
            for char in guessStr:
                myDict[word][char]=[]
                for other in myDict:
                    if match(word,other,char):
                        myDict[word][char].append(other)
        for j in range(nlists):
            hisStr = str(f.readline())
            best = ""
            bestScr = -1
            for word in myList:
                trial = score(word,myDict,hisStr)
                if trial>bestScr:
                    bestScr=trial
                    best=word
            g.write(" ")
            g.write(best)
        g.write("\n")
    f.close()
    g.close()
    
