def accr(k):
    #gets you from 10^k to 10^k+1
    return 10**( (k+1)/2) + 10**( (k+2)/2) -1

def solve(N):
    if N <= 10: return N
    d = len(str(N))
    #First, get to 10^(d-1)
    ans = 0
    for i in xrange(d-1):
        ans += accr(i)
    #Now you are at 10^(d-1)
    #given that the tail isnt zeros, you can do the usual
    S = str(N)
    head,tail = S[:d/2],S[d/2:]
    if tail.count('0') != len(tail):
        #usual case, now add up the reverse of head
        #plus the reversal, plus the tail minus one
        
        ans += int(head[::-1])
        ans += int(tail)
        #There's a correction - if we dont need to reverse,
        #then we subtract one.  It happens when the head is
        #equal to 1 followed by 0's
        if head == '1'+'0'*(len(head)-1): ans -= 1
        return ans
    else:
        #in an unusual case, start one less on the head then proceed
        #First, is the head suitable?  Then no need to do work
        if head == '1'+'0'*(len(head)-1): return ans
        #Now fix corner case we mess up
        ans += 1
        z = int(head)
        if z < 3:
            ans -= 1
        elif (z >= 10 and z < 12): ans -= 1
        elif (z >= 10**2 and z < 10**2 + 2): ans -= 1
        elif (z >= 10**3 and z < 10**3 + 2): ans -= 1
        elif (z >= 10**4 and z < 10**4 + 2): ans -= 1
        elif (z >= 10**5 and z < 10**5 + 2): ans -= 1
        elif (z >= 10**6 and z < 10**6 + 2): ans -= 1
        elif (z >= 10**7 and z < 10**7 + 2): ans -= 1
        elif (z >= 10**8 and z < 10**8 + 2): ans -= 1

        head = int(head)-1
        head = str(head)
        ans += int(head[::-1])
        #Now add up the remaining work: you are at head + '0'*lentail + 1
        #and you want to be at N

        ans += N - int( head+'0'*len(tail) ) - 1
        return ans
    
########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        zetaans = solve(N)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
