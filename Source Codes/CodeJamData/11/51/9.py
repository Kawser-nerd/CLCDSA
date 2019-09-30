import math

def getPos(x,p1,p2):
    x1,y1 = p1
    x2,y2 = p2
    return y1+1.0*(y2-y1)*(x-x1)/(x2-x1)
    
fi = open("input.txt")
for turn in range(int(fi.readline())):
    w,l,u,g = map(int,fi.readline().split())
    L ,U= [],[]
    S = 0
    for i in range(l):
        x,y = map(float,fi.readline().split())
        L.append((x,y))
        if i>0:
            S-= (L[i][1]+L[i-1][1])*(L[i][0]-L[i-1][0])
    for i in range(u):
        x,y = map(float,fi.readline().split())
        U.append((x,y))
        if i>0:
            S+= (U[i][1]+U[i-1][1])*(U[i][0]-U[i-1][0])
    #merge
    i,j = 0,0
    cur = U[0][1]-L[0][1]
    x = 0
    print "Case #{0}:".format(turn+1)
    s0 = 0
    getNext = True
    U.append((w+1,0))
    L.append((w+1,0))
    for it in range(g-1):
        s = S*1.0/g
        while s>0:
            if getNext:
                #print x,U[i+1],L[j+1]
                if x>=U[i+1][0]:
                    i+=1
                if x>=L[j+1][0]:
                    j+=1
                if U[i+1][0]<L[j+1][0]:
                    x2 = U[i+1][0]
                    cur2=U[i+1][1]-getPos(x2,L[j],L[j+1])
                elif U[i+1][0]>L[j+1][0]:
                    x2 = L[j+1][0]
                    cur2=getPos(x2,U[i],U[i+1])-L[j+1][1]
                else:
                    x2 = U[i+1][0]
                    cur2=U[i+1][1]-L[j+1][1]
            if s>(cur+cur2)*(x2-x):
                s-=(cur+cur2)*(x2-x)
                s0 += (cur+cur2)*(x2-x)
                x,cur = x2,cur2
                getNext = True
            else:
                #print cur,cur2
                cur1 = cur
                ratio = s*1.0/((cur+cur2)*(x2-x))
                cur = math.sqrt(cur**2-ratio*(cur**2-cur2**2))
                x += s/(cur+cur1)
                s0 +=s
                s = 0
                getNext = False
        print x
        