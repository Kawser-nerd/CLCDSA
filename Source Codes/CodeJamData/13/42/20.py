from collections import defaultdict
from itertools import permutations
#f=open("input")
#f=open("B-small-attempt0.in","rb")
f=open("B-large.in","rb")
ff=open("output", "w")
readint=lambda :int(f.readline())
readintarray=lambda :map(int, f.readline().split())
T=readint()
def simulate(pi, N):
    result={0:pi}
    for i in range(N):        
        newresult=defaultdict(list)
        for s in result:
            teams=result[s]
            #print s, teams
            for ti in range(0,len(teams),2):                
                if teams[ti]<teams[ti+1]:
                    newresult[2*s].append(teams[ti])
                    newresult[2*s+1].append(teams[ti+1])
                else:
                    newresult[2*s+1].append(teams[ti])
                    newresult[2*s].append(teams[ti+1])
        result=newresult
        #print result
    rtn=[0]*2**N
    #print "r",result
    for i in range(2**N):
        rtn[result[i][0]]=i
    return rtn
                    
                    
def func(n,N):
    r=1
    if n==0:
        return r
    S=1
    L=2**(N-1)    
    while 1:
        if n < S:
            return r
        S+=L
        L/=2
        r*=2
def func2(n,N):
    return N2-func(N2-n-1,N)+1
def bi(P,N, x1,x2, fn):
    if x1+1==x2:
        return x1
    y=(x1+x2)/2
    if fn(y,N)>P:
        return bi(P,N,x1,y,fn)
    else:
        return bi(P,N,y,x2,fn)
    
    
for casex in range(1,T+1):

#for casex in range(1,2):
    N,P=readintarray()    
    print  "Case #%d:"%casex, N,P
    N2=2**N
    print bi(P,N,0,N2,func2), bi(P,N,0,N2,func)
    print  >>ff, "Case #%d:"%casex, bi(P,N,0,N2,func2), bi(P,N,0,N2,func)
   
    
        

    #print  >>ff, "Case #%d:"%casex, (cost0-cost1)%1000002013
print "done"
ff.close()
