T = int(raw_input())
for t in range(1,T+1):
    A,B = [int(x) for x in raw_input().split()]
    P = [float(x) for x in raw_input().split()]
    Best = B+2.
    prob_right = 1
    for i in range(A):
        prob_right*=P[i]
        
        EV = (2*B+2+A - 2*(i+1))-prob_right*(B+1)
        if EV<Best:
            Best = EV
    print "Case #"+str(t)+":", Best
