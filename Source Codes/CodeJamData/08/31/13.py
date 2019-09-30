import sys

for case in range(1, int(sys.stdin.readline())+1):
    (P, K, L) = map(int, sys.stdin.readline().split(' '))
    data = zip(map(int, sys.stdin.readline().split(' ')), range(L))
    data.sort(key=lambda z: z[0], reverse=True)
    assigned=[]
    for i in range(K):
        assigned.append(0)
    k=0
    press = 0
    for d in data:
        assigned[k]+=1
        if(assigned[k] > P):
            break
        press += d[0]*assigned[k]
        k+=1
        if(k>=len(assigned)):
            k=0
    if(assigned[k] > P):
        print "Case #%d: Impossible" % (case)    
    else:
        print "Case #%d: %d" % (case, press)    
