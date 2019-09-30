#!/usr/bin/python

# Run by:
#     cat input | c.py

import sys
from math import sqrt, atan, pi, ceil

def arc_area(x1, y1, x2, y2, r):
    """The area of a right triangle with given points, including the arc of a circle of radius r."""

    assert y2 > y1, '%r is not greater than %r' % (y2, y1)
    assert x1 > x2, '%r is not greater than %r' % (x2, x1)
    
    # Start with the triangle
    area = 0.5*abs(x2-x1)*abs(y2-y1)
    
    # Find the area of the angle covered by the points
    theta2 = atan(y2/x2)
    theta1 = atan(y1/x1)
    assert theta2 > theta1
    theta = theta2 - theta1
    area_theta = 0.5*theta*r**2
    
    # Calculate the area of the triangle from the origin to the 2 points
    a = r
    b = r
    c = sqrt((y2-y1)**2 + (x2-x1)**2)
    s = 0.5*(a + b + c)
    area_triangle = sqrt(s*(s-a)*(s-b)*(s-c))

#    assert area_theta >= area_triangle, "%r is not greater than %r" % (area_theta, area_triangle)
    area += (area_theta - area_triangle)
    return area
    
def intersection(x, y, l, r):
    """The area of a square located at x,y with edge length l that is within a cirle of radius r centered at 0,0."""
    if x**2 + y**2 >= r**2 or l <= 0:
        return 0.0
    
    if (x+l)**2 + (y+l)**2 <= r**2:
        return l**2
    
    area = 0.0
    
    # Determine which points of the square are outside the circle
    out_2 = ((x+l)**2 + y**2 >= r**2)
    out_3 = (x**2 + (y+l)**2 >= r**2)
    
    if out_2 and out_3:
        # All there is is an arc and triangle
        area += arc_area(sqrt(r**2 - y**2), y, x, sqrt(r**2 - x**2), r)
    elif out_2:
        dx = sqrt(r**2 - (y+l)**2)
        assert dx > x
        area += l*(dx - x)
        area += arc_area(sqrt(r**2 - y**2), y, dx, y+l, r)
    elif out_3:
        dy = sqrt(r**2 - (x+l)**2)
        assert dy > y
        area += l*(dy - y)
        area += arc_area(x+l, dy, x, sqrt(r**2 - x**2), r)
    else:
        dx = sqrt(r**2 - (y+l)**2)
        assert dx > x
        area += l*(dx - x)
        dy = sqrt(r**2 - (x+l)**2)
        assert dy > y
        area += (l - (dx - x))*(dy - y)
        area += arc_area(x+l, dy, dx, y+l, r)

    return area

l = sys.stdin.readline()
n = int(l)

for i in range(n):
    print 'Case #%d:' % (i+1,),

    l = sys.stdin.readline()
    (f, R, t, r, g) = [float(x) for x in l.split()]
    
    free_area = 0.0
    
    num = int(ceil((R - t - r)/(g + 2*r)))
    for i in range(num):
        for j in range(num):
            free_area += intersection(f + r + i*(g + 2*r), f + r + j*(g + 2*r), g - 2*f, R - t - f)
            
    free_area = free_area * 4.0
    ratio = 1.0 - free_area / (pi*R**2)

    print '%0.8f' % ratio
    