import fileinput

def findTcar(D,N,tx):
    for i in xrange(N):
        t2,x2 = tx[i]
        if x2>=D:
            if i==0:
                return 0.0
            t1,x1=tx[i-1]
            return t1+(D-x1)*(t2-t1)/(x2-x1)
            
def overlaps(tx,D,a,t0,tcar):
    for t,x in tx:
        if x<(a/2*((max(0.0,t-t0))**2)):
            #print '(a/2*((t-t0)**2))',(a/2*((t-t0)**2))
            
            if x<D:
                t0 = t - (2*x/a)**0.5
            #if t01
            #return overlaps(tx,D,a,t01,tcar)
    
    return t0+(2*D/a)**0.5


inp=fileinput.input()
line=inp.next()
T=int(line)

for case in xrange(T):
    line=inp.next()
    inputs=line.split(' ')
    D=float(inputs[0])
    N=int(inputs[1])
    A=int(inputs[2])

    tx=[]
    for i in xrange(N):
        line=inp.next()
        inputs=line.split(' ')
        tx.append((float(inputs[0]),float(inputs[1])))

    acc=[]
    line=inp.next()
    inputs=line.split(' ')
    for i in xrange(A):
        acc.append(float(inputs[i]))
    
    print 'Case #%s:'%(case+1)
    for a in acc:
        tcar=findTcar(D,N,tx)
        t0=tcar-(2*D/a)**0.5
        if t0<0:
            t0=0
            tcar=(2*D/a)**0.5
        #print 'tcar',tcar
        time = overlaps(tx,D,a,t0,tcar)
        print time
    
    #print a
    #string=inp.next()
    
    if case+1>T:
        break
