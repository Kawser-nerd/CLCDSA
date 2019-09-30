from math import *

# x value of intersection with circle given y
def xGivenY(y, rad):
    return sqrt(rad**2 - y**2)

# y value of intersection with circle given x
def yGivenX(x, rad):
    return sqrt(rad**2 - x**2)

def indefinite(x,rad):
    return (x*sqrt(rad**2 - x**2) + rad**2*asin(x/rad))/2.0

def integrate(x0,x1,rad):
    return indefinite(x1,rad) - indefinite(x0,rad)

                     

filename = raw_input("Enter input file name: ")
input = file(filename,'r')

filename = raw_input("Enter output file name: ")
output = file(filename,'w')

numCases = eval(input.readline())

# print 'number of cases: ', numCases

for case in range(numCases):

    (f, R, t, r, g) = [float(eval(x)) for x in input.readline().split()]

#    print 'case, f, R, t, r, g: ', f, R, t, r, g

    cellSize = 2.0*r + g
    Rtf2 = (R-t-f)**2

    totalArea    = pi*R**2/4.0 
    passableArea = 0.0

    if 2.0*f >= g:
        print 'Case #%s: %.6f' % (case+1, 1.0 - passableArea/totalArea)
        output.write('Case #%s: %.6f\n' % (case+1, 1.0 - passableArea/totalArea))
        continue

    maxArea = (g - 2.0*f)**2

    x = r
    while x+f < R-t-f:
        y = r
        while (y+f)**2 + (x+f)**2 < Rtf2:
            # figure out which corners, if any, are chopped off
            c1 = (x+g-f)**2 + (y+f)**2    # bottom right
            c2 = (x+g-f)**2 + (y+g-f)**2  # upper right
            c3 = (x+f)**2   + (y+g-f)**2  # upper left
            
            if (c2 <= Rtf2):
                # all corners inside
                passableArea = passableArea + maxArea

            elif (c1 <= Rtf2 and c3 <= Rtf2):
                # only c2 chopped off
                yTop = y + g - f
                xTop = xGivenY(yTop,R-t-f)
                xRight = x + g - f
                yRight = yGivenX(xRight,R-t-f)
                yLength = g - 2.0*f
                xLength = xTop - (x + f)
                area = integrate(xTop,xRight,R-t-f)
                area = area - (xRight-xTop)*(y + f)
                if (area > 0 and yTop > yRight and xTop < xRight and xLength > 0.0):
                    passableArea = passableArea + yLength*xLength + area

            elif (c1 <= Rtf2 and c3 > Rtf2):
                # c2 and c3 chopped off -- the top
                xLeft = x + f
                yLeft = yGivenX(xLeft,R-t-f)
                xRight = x + g - f
                yRight = yGivenX(xRight,R-t-f)
                areaAll = integrate(xLeft,xRight,R-t-f)
                area = areaAll - (xRight-xLeft)*(y+f)
                if (area > 0 and xLeft < xRight and yLeft > yRight):
                    passableArea = passableArea + area

            elif (c1 > Rtf2 and c3 <= Rtf2):
                # c1 and c2 chopped off -- the right chopped off
                yTop = y + g - f
                xTop = xGivenY(yTop,R-t-f)
                yBottom = y + f
                xBottom = xGivenY(yBottom,R-t-f)
                areaAll = integrate(xTop,xBottom,R-t-f)
                area = areaAll - (xBottom-xTop)*yBottom
                yLength = g - 2.0*f
                xLength = xTop - (x + f)
                if (area > 0 and xBottom > xTop and yBottom < yTop and xLength > 0.0):
                    passableArea = passableArea + yLength*xLength + area

            elif (c1 > Rtf2 and c3 > Rtf2):
                # c1, c2, and c3 chopped off -- only inner corner inside
                xLeft = x + f
                yLeft = yGivenX(xLeft,R-t-f)
                yBottom = y + f
                xBottom = xGivenY(yBottom,R-t-f)
                areaAll = integrate(xLeft,xBottom,R-t-f)
                area = areaAll - (xBottom-xLeft)*yBottom
                if (area > 0 and xLeft < xBottom and yLeft > yBottom):
                    passableArea = passableArea + area
            else:
                print "shouldn't get here!"


            y = y + cellSize

        x = x + cellSize

    print 'Case #%s: %.6f' % (case+1, 1.0 - passableArea/totalArea)
    output.write('Case #%s: %.6f\n' % (case+1, 1.0 - passableArea/totalArea))
