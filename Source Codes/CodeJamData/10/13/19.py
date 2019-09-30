def xl(l):
    return xrange(len(l))

def calc(a,b):
    if a>=2*(b-a): return False
    return (not calc(b-a,a))

def yadd(a1,a2,b1,b2):
    y=0
    #print a1,a2,b1,b2
    for a in xrange(a1,min(a2,b2)):
        for b in xrange(max(a+1,b1),min(2*a,b2)):
            #print a,b,calc(a,b)
            y+=calc(a,b)
        #print max(0,b2-max(b1,2*a))
        y+=max(0,b2-max(b1,2*a))
    return y

for case in range(input()):
    print "Case #"+str(case+1)+":",
    a1,a2,b1,b2=map(int,raw_input().split())
    a2+=1
    b2+=1
    y=0
    y+=yadd(a1,a2,b1,b2)
    a1,a2,b1,b2=b1,b2,a1,a2
    y+=yadd(a1,a2,b1,b2)
    print y
