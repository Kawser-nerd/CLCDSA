from collections import defaultdict

#f=open("input")
f=open("A-large.in","rb")
ff=open("output", "w")
readint=lambda :int(f.readline())
readintarray=lambda :map(int, f.readline().split())
T=readint()
    
for casex in range(1,T+1):
    N,M=readintarray()
    off=defaultdict(int)
    on=defaultdict(int)
    stations=set()
    cost0=0
    for x in range(M):
        o,e,p=readintarray()
        cost0+=((e-o)*N-(e-o)*(e-o-1)/2)*p        
        on[o]+=p
        off[e]+=p
        stations.add(o)
        stations.add(e)
    stations=sorted(list(stations))
    print  "Case #%d:"%casex
    #print N,M,on,off,stations
    tickets=[]
    cost1=0
    for s in stations:
        if on[s]>0:
            tickets.append([s,on[s]])
            #print "on", s, tickets
        if off[s]>0:
            offs=off[s]
            #print "off",s,tickets
            while 1:
                #print "s",s, tickets, offs
                t,n=tickets[-1]
                if n>= offs:
                    cost1+=((s-t)*N-(s-t)*(s-t-1)/2)*offs
                    tickets[-1]=[t,n-offs]
                    break
                else:
                    cost1+=((s-t)*N-(s-t)*(s-t-1)/2)*n
                    offs-=n
                    tickets.pop()
    print (cost0-cost1)%1000002013
    print  >>ff, "Case #%d:"%casex, (cost0-cost1)%1000002013
print "done"
ff.close()
