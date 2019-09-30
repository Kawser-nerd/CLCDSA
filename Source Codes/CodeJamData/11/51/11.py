import sys, collections


infile = sys.stdin

def get_cuts(lower, upper, npieces):
    # split polygon into trapezoids
    li = ui = 0
    areas = [] # (left x, right x, left height, right height, area of segment, total running area)
    total_area = 0
    x = 0
    h1 = upper[0][1]-lower[0][1]
    W = lower[-1][0]
    while x<W:
        # next vertex in x-direction from upper or lower
        lnext = lower[li+1]
        unext = upper[ui+1]
        if lnext[0]==unext[0]:
            xnext = lnext[0]
            h2 = unext[1]-lnext[1]
            li += 1
            ui += 1
        elif lnext[0]<upper[ui+1][0]:
            xnext = lnext[0]
            frac = 1.0*(xnext-upper[ui][0]) / (unext[0]-upper[ui][0])
            yupper = upper[ui][1] + frac*(unext[1]-upper[ui][1])
            h2 = yupper - lnext[1]
            li += 1
        else:
            xnext = unext[0]
            frac = 1.0*(xnext-lower[li][0]) / (lnext[0]-lower[li][0])
            ylower = lower[li][1] + frac*(lnext[1]-lower[li][1])
            h2 = unext[1] - ylower
            ui += 1

        da = (xnext-x) * (h1+h2)/2.0
        total_area += da
        areas.append((x, xnext, h1, h2, da, total_area))
        x = xnext
        h1 = h2
            
    # iterate over computed trapezoids, making cuts when we hit required areas
    size = total_area / npieces
    cuts = []
    needed = size
    for x1,x2,h1,h2,segment_area,total_area in areas:
        segment_remaining = segment_area
        area_from_left = 0
        while segment_remaining >= needed:
            area_from_left += needed
            width = x2-x1
            #print h1,h2,width,area_from_left, segment_area
            # determine x so that area from left side to x is area_from_left
            # height at x = hx = h1 + (x/width)*(h2-h1) = (x/width)*h2 + (1-x/width)*h1
            # area = x*(h1+hx)/2 = h1*x + ((h2-h1)/(2*width))*(x**2)
            # solve quadratic, unless h1=h2 in which case it's linear
            if (h1==h2):
                x = area_from_left / h1
            else:
                qa = (h2-h1)/(2*width)
                qb = h1
                qc = -area_from_left
                # h1>0, take positive discriminant
                #print qb**2 - 4*qa*qc
                x = (-qb + (qb**2 - 4*qa*qc)**0.5)/(2*qa)
                
            cuts.append(x1+x)
            #print "Got cut: " + str(x1+x)
            if len(cuts)==npieces-1:
                return cuts
            
            segment_remaining -= needed
            needed = size
            
        needed -= segment_remaining
            
    

T = int(infile.readline())
for i in xrange(T):
    W, L, U, G = map(int, infile.readline().split())
    lower = []
    upper = []
    for j in xrange(L):
        lower.append(map(float, infile.readline().split()))
    for j in xrange(U):
        upper.append(map(float, infile.readline().split()))

    result = get_cuts(lower, upper, G)

    print("Case #%d:" % (i+1,))
    for r in result:
        print(r)
