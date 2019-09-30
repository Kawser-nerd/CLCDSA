def readline():
    return [int(x) for x in raw_input().split(' ')]

def isSolvable(keys, chests, groups):
    def openchest(chest):
        keys[chests[chest][0]]-=1
        for k in chests[chest][1]: keys[k]+=1
        groups[chests[chest][0]].remove(chest)
    

    #print keys
    #print chests
    #print groups
    
    while True:
        rule1 = False
        for i in range(len(keys)):
            if keys[i]==0: continue
            color=[0]*210
            trail = []
            
            def dfs(x):
                color[x]=1
                for chest in groups[x]:
                    trail.append(chest)
                    for g in chests[chest][1]:
                        if g==i: raise 1
                        if color[g]==2: continue
                        if color[g]==1: continue
                        dfs(g)
                    del trail[-1]
                color[x]=2

            try:
                dfs(i)
            except:
                rule1=True
                #print "Applying rule 1 to ", trail
                openchest(trail[0])
        if rule1: continue

        rule2 = False
        for i in range(len(keys)):
            if len(groups[i])==0: continue
            if len(groups[i])<=keys[i]:
                rule2 = True
                #print "Applying rule 2 to ", groups[i]
                for chest in groups[i][:]:
                    openchest(chest)
        if rule2: continue
        break

    for i in range(len(keys)):
        if len(groups[i])>0:
            return False
    return True

n = readline()[0]
for v in range(n):
    keys=[0]*210
    chests=[]
    opened=[]
    groups=[[] for i in range(210)]
    order = []
    
    K,C=readline()
    for i in readline():
        keys[i]+=1
    for i in range(C):
        l = readline()
        chests.append((l[0],l[2:]))
        groups[l[0]].append(i)
        opened.append(False)
        
    def openchest(chest):
        keys[chests[chest][0]]-=1
        for k in chests[chest][1]: keys[k]+=1
        groups[chests[chest][0]].remove(chest)

    if not isSolvable(keys[:], chests, [x[:] for x in groups]):
        print "Case #%d: IMPOSSIBLE"%(v+1)
    else:
        while len(order) < C:
            for i in range(C):
                if opened[i]: continue
                if keys[chests[i][0]]==0: continue
                openchest(i)
                if isSolvable(keys[:], chests, [x[:] for x in groups]):
                    opened[i]=True
                    order.append(i+1)
                    break
                keys[chests[i][0]]+=1
                for k in chests[i][1]: keys[k]-=1
                groups[chests[i][0]].append(i)
        print "Case #%d: %s"%(v+1,' '.join(str(x) for x in order))

        
                
                    
                    
