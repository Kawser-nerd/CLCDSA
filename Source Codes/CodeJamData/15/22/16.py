
def solve(R,C,N):
    #print R,C,N,'RCN'
    if R==1 or C==1:
        if R!=1: R,C=C,R
        #R==1 now
        if N <= (C+1)/2: return 0
        #Now it gets tricky, there are corners
        if C%2==0:
            N -= (C+1)/2
            if N == 1: return 1
            return 2*N - 1
        else:
            N -= (C+1)/2
            return 2*N
    elif R==2 or C==2:
        if R!=2: R,C=C,R
        if N <= (R*C + 1)/2: return 0
        #Now there are two corners and rest is 3s
        N -= (R*C+1)/2
        if N<=2: return 2*N
        return 3*N-2
    
    P= R*C
    if N<=(P+1)/2: return 0
    #print R,C,'RC'
    Q = ((R-2)*(C-2)+1)/2
    Rem = P-N
    #print Q,Rem,'Qrem'
    if Rem<=Q: return 2*R*C-R-C-4*Rem
    start = 2*R*C-R-C
    #We want to subtract from start to get our ans
    # We have Rem white squares to deal with
    #For both types of checkerings, lets count
    #the number of inside, side, and corner

    #Checkering number one: even indexes
    a = [0,0,0]
    b = [0,0,0]
    #inside, side, corner
    for i in xrange(R):
        for j in xrange(C):
            if (i+j)%2==0:
                sides = 0
                if i==0 or i==R-1: sides+=1
                if j==0 or j==C-1: sides+=1
                a[sides] += 1
            else:
                sides = 0
                if i==0 or i==R-1: sides+=1
                if j==0 or j==C-1: sides+=1
                b[sides] += 1

    #Now lets find both answers.  The person with the highest subtraction wins
    sub1 = 0
    G = int(Rem)
    if G <= a[0]:
        sub1 += 4*G
    elif G <= a[0]+a[1]:
        sub1 += 4*a[0]
        sub1 += 3*(G-a[0])
    else:
        sub1 += 4*a[0]
        sub1 += 3*a[1]
        sub1 += 2*(G-a[0]-a[1])

    sub2 = 0
    if G <= b[0]:
        sub2 += 4*G
    elif G <= b[0]+b[1]:
        sub2 += 4*b[0]
        sub2 += 3*(G-b[0])
    else:
        sub2 += 4*b[0]
        sub2 += 3*b[1]
        sub2 += 2*(G-b[0]-b[1])
    #print 'prob'
    #print start, a,b,sub1,sub2
    return min(start-sub1,start-sub2)

#i=3
#j=3
#for k in xrange(i*j/2,i*j+1): print solve(i,j,k), '.'
"""
def solve(R,C,N):
    P = R*C
    if P%2==1: #odd lengths
        #The first (p+1)/2 are free
        if N <= (P+1)/2: return 0

        #Lets see if we can white checker, if we can do that
        Q = ((R-1)*(C-1)+1)/2
        Rem = P-N
        if Rem <= Q:
            #We can white checker, do that instead
            return 2*R*C-R-C-4*Rem
        
        #Then, there are R+C-1 edges to use
        N -= (P+1)/2
        if N <= R+C-1: return 3*N
        N -= (R+C-1) #used all the edges
        return 4*N + 3*(R+C-1)
    else: #atleast one even side
        if N <= P/2: return 0 #first checker is free

        #Lets see if we can white checker, if we can do that
        Q = ((R-1)*(C-1)+1)/2
        Rem = P-N
        if Rem <= Q:
            #We can white checker, do that instead
            return 2*R*C-R-C-4*Rem
        #Then, there are some corners
        N -= P/2
        if N <= 2: return 2*N
        if N <= R+C-1: return 3*N-2
        N -= R+C-1
        return 4*N + 3*(R+C-1) - 2"""

        
    
########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        R,C,N = rrM()
        zetaans = solve(R,C,N)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
