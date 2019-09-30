

from itertools import product
from itertools import combinations

#F = open('C-small-attempt0.in')
#O = open('C-small-attempt01.out','w')

F = open('C-large.in')
O = open('C-large.out','w')

T = int(F.readline())

print T

for case in range(1,T+1):
    J,P,S,K = map(int,F.readline().rstrip().split())


    x = combinations(list(str(i) for i in range(1,S+1)),min(S,K))
    t = []
    for i in x:
        t.append(i)

    q = len(t)

    ans = J * P * min(S,K)
    O.write("Case #%d: %d\n"%(case,ans))
    #print ans,J,P,S,K,len(t)

    for j in range(1,J+1):
        for p in range(1,P+1):
            for s in range(1,min(S,K)+1):
                string = str(j) + ' ' + str(p) + ' ' + str((s+j-1+p-1)%S+1)
                #print string
                O.write("%s\n"%(string))



    
F.close()
O.close()
