import sys

import math

def ff(x,rad):
    return math.sqrt(rad**2 - x**2)

def FF(x,rad):
    x = min(x, rad-1e-9)
        
    
    theSqrt = ff(x,rad)
    result = 0.5 * (math.atan(x/theSqrt)*(rad**2) + x*theSqrt)
    return result

def integral(a,b,rad):
    return FF(b,rad)-FF(a,rad)
    
def isInCircle(x,y,rad):
    return x**2 + y**2 <= rad**2

def analyzeSquare(x1,y1,x2,y2,rad):
    if not (x1<=x2 and y1<=y2):
        return 0.
    if isInCircle(x2,y2,rad):
        # entire square is inside
        area = (x2 - x1) * (y2 - y1)
    elif (not isInCircle(x1,y1,rad)):
        # entire square is outside
        area = 0
    elif (not isInCircle(x1,y2,rad)):
        # hits 0-1 at y=a
        if (isInCircle(x2,y1,rad)):
            # case 3
            area = integral(x1,x2,rad) - (x2-x1)*y1
        else:
            # case 1
            # b = x coord of intersection with y=y1
            b = math.sqrt(rad**2 - y1**2)
            assert(x1<=b<=x2)
            area = integral(x1,b,rad) - (b-x1)*y1
    else:
        # hits 1-2 at x=a, y=y2
        a = math.sqrt(rad**2 - y2**2)
        assert(x1<=a<=x2)
        if (isInCircle(x2,y1,rad)):
            # case 2
            area = (a-x1)*(y2-y1) + integral(a,x2,rad) - (x2-a)*y1 
        else:
            # case 4
            # b = intesection of 0-3 at y=y1 
            b = math.sqrt(rad**2 - y1**2)
            assert(x1<=b<=x2)
            area = (a-x1)*(y2-y1) + integral(a,b,rad) - (b-a)*y1
    
    return area

def sampleArea(x1,y1,x2,y2,rad,n):
    count = 0
    for i in range(n):
        x = x1 + i*(x2-x1)/n
        for j in range(n):
            y = y1 + i*(y2-y1)/n
            if isInCircle(x,y,rad):
                count += 1
                
    return (x2-x1)*(y2-y1)*count/(n*n)
            

def calc(f, R, t, r, g):
    rad = R-t-f
    
    totalArea = 0.
    x1 = r+f
    x2 = r+g-f
    if (x1 >= x2):
        pass
    while (x1 < R-t):
        y1 = r+f
        y2 = r+g-f
        
        while (y1 < R-t):
            area = analyzeSquare(x1,y1,x2,y2,rad)
            #area2 = sampleArea(x1,y1,x2,y2,rad,100)
            #print "A: ", area, area2
            totalArea += area
            
            y1 += g+2*r
            y2 += g+2*r
        
        x1 += g+2*r
        x2 += g+2*r
        
    racquetArea = math.pi*(R**2)/4
    ratio = 1 - totalArea/racquetArea
    return ratio


fin = open(sys.argv[1])
nCases = int(fin.readline())
for j in range(nCases):
    f, R, t, r, g  = [float(x) for x in fin.readline().split()]
    area = calc(f, R, t, r, g)
    print "Case #%d: %f" % (j+1,area) 