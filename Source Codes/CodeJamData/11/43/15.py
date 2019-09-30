from numpy import *

def Worst(n):
    Cost = 1;
    Time = 1;
    for i in range(2,n+1):
        if Cost == 0 or Cost%i != 0:
            k = Cost;
            while (Cost%i != 0):
                Cost += k;
            Time += 1;
    return Time



P = [2];
k = 3;
while (k < 1000):
    isP = True;
    for p in P:
        if k%p == 0:
            isP = False;
    if isP:
        P.append(k);
    k += 2;

#print P;            
        

    

def Best(n):
    Time = 0;
    for p in P:
        if p <= n:
            Time += 1;
    return Time
    


T = int(raw_input());
for i in range(T):
    print "Case #%d:" % (i+1),;
    N = int(raw_input());

    Bad = Worst(N);
#    print N, Worst(N), Best(N)
    if N == 1:
        print 0;
    else:
        print Worst(N) - Best(N)
