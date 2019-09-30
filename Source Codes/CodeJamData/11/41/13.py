from operator import itemgetter
fi = open("input.txt")

for run in range(int(fi.readline())):
    X,S,R,t,N = map(int,fi.readline().split())
    ww = []
    for i in range(N):
        ww.append(map(int,fi.readline().split()))
        
    ww.sort()
    last = X
    for i in range(len(ww)-1,-1,-1):
        b,e,v = ww[i]
        ww[i][2] +=S
        if e!=last:
            ww.append([e,last,S])
        last = b
    if last>0:
        ww.append([0,last,S])
    #ww.sort()
    
    R -=S
    
    ww.sort(key=itemgetter(2))
    #print ww,R
    res = 0.0
    for b,e,v in ww:
        if e-b<=(v+R)*t:
            time = 1.0*(e-b)/(v+R)
            res+=time
            t-=time
        else:
            time = 1.0*(e-b-t*(v+R))/v+t
            #print e-b-t*(v+R)
            res+=time
            t = 0
        #print res
            
    print "Case #{0}: {1}".format(run+1,res)
                    