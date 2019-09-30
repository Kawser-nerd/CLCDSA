


f = open(r'C:\goog\B-large.in')

numcases=int(f.readline())
for case in range(numcases):
    line=f.readline().strip()
    numflavors=int(line)
    
    line=f.readline().strip()
    numcust=int(line)
    
    cust=[]
    
    for i in range(numcust):
        line=f.readline().strip()
        numbers=map(int, line.split(' '))
        
        numlikes=numbers[0]
        likesnormal=[]
        likesmalted=[]
        for j in range(numlikes):
            if numbers[j*2+2]==0:
                likesnormal.append(numbers[j*2+1])
            else:
                likesmalted.append(numbers[j*2+1])
        if len(likesmalted)>1: raise
        cust.append((likesnormal,likesmalted))
        
    flavors = [0] * numflavors
    
    custdone = [False] * numcust
    
    impossible=False
    
    while True:
        nothingchanged=True
        for i in range(numcust):
            if custdone[i]: continue
            if len(cust[i][0])==0:
                if len(cust[i][1])==0:
                    impossible=True
                    break
                else:
                    malted=cust[i][1][0]
                    custdone[i]=True
                    if flavors[malted-1]!=1:
                        flavors[malted-1]=1
                        nothingchanged=False
                        for j in range(numcust):
                            if malted in cust[j][0]:
                                cust[j][0].remove(malted)
        if impossible: break
        if nothingchanged: break
    
    if impossible:
        result="IMPOSSIBLE"
    else:
        result= ' '.join(map(str,flavors))
    
    

    print "Case #" + str(case+1) + ": " + result
            

        






