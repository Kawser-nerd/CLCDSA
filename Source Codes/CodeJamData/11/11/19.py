def simp(n):
    j=100
    k = n
    if n%4 ==0:
        j=j/4
        k=k/4
    elif n%2 ==0:
        j=j/2
        k=k/2
    if n%25 ==0:
        j=j/25
        k=k/25
    elif n%5 ==0:
        j=j/5
        k=k/5
    return (k,j)

def works(maxD,pd,pg):
    (numd,dend)=simp(pd)
    (numg,deng)=simp(pg)
    if dend>maxD:
        return False
    if (pg==0) and (pd!= 0):
        return False
    if (pg==100) and (pd != 100):
        return False
    return True
    

def run():
    f=open("input.in")
    g=open("out.txt",'w')
    num = int(f.readline())
    for i in range(num):
        g.write("Case #%d: " % (i+1))
        [maxD, pd, pg] = map(int,f.readline().split())
        if works(maxD,pd,pg):
            g.write("Possible\n")
        else:
            g.write("Broken\n") 
    f.close()
    g.close()
    
