
def solve(N,A):
    #print N,A
    #Each item in A is a group: D, H, M
    #Representing H hikers starting at D that take M, M+1, ... M+H-1 to revolve
    #Lets try to stunt the small quickly
    B = []
    for d,h,m in A:
        for i in xrange(h):
            B.append((d,m+i))
    #B are all the hikers
    
    #If theres only one hiker, you can do it
    if len(B)<=1: return 0
    B.sort()
    a,x = B[0]
    b,y = B[1]
    #a<=b
    #Try to do it in zero, if you can't, youll do it in one.
    #If A is slower than B, then it only matters if they cross
    if x==y: return 0
    if x>y: #A is slower
        #The only way is if B can run 720-b before A can run 360-a
        #with equality being bad for us.
        #Recall A has speed 1revolution/Xminutes
        if (720-b)*y <= (360-a)*x:
            return 1
        else: return 0
    else:
        #A is faster than B, so he might overtake B before the finish line.
        #If he doesn't, then we are good.  Else, we still might be good-
        # A would have to meet B again.
        #Lets see if A meets B twice before the finish line.
        #When B runs 360-b, A would have to run atleast 720-a.
        if (720-a)*x <= (360-b)*y:
            return 1
        return 0
    return 1
    
        
    
########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        A = [rrM() for i in xrange(N)]
        zetaans = solve(N,A)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
