T = int(raw_input())
for t in range(T):
    N = int(raw_input())
    L=[]
    for n in range(N):
        L+=[[int(x) for x in raw_input().split()]]
    level1 = [0]*N
    level2 = [0]*N
    done = False
    stars = 0
    games = 0
    while not done:
        done = True
        #Search for any level twos that can be can be reached
        for stage in range(N):
            if level2[stage]==0 and stars>= L[stage][1]:
                games+=1
                stars+=2 - level1[stage]
                level2[stage]=1
                level1[stage]=1
                done = False
        if done:
            candidates = [stage for stage in range(N) if L[stage][0]<=stars and level1[stage]==0]
            if len(candidates)>0:
                candidates.sort(key = lambda x: L[x][1])
                candidates.reverse()
                stars+=1
                level1[candidates[0]]=1
                done = False
                games+=1
    if stars < 2*N:
        print "Case #"+str(t+1)+": Too Bad"
    else:
        print "Case #"+str(t+1)+":", games
            
            
