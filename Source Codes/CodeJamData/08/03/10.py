#!/usr/bin/python
import math

def odcinek_field_x(r, xr):
    # 1. punkty przeciecia pionu z okregiem
    # x^2 + y^2 = r^2
    # x = xr, y=?
    if xr >= r:
        return 0.0
    
    yr = math.sqrt(r**2 - xr**2)
    #print (xr,yr)
    
    # 2. kat do obliczenia wycinka
    # kat pomiedzy (0,0) a (xr, yr)
    # a/b = tg(alpha)
    alpha = math.atan2(yr, xr)
    alpha *= 2.0
    
    # 3. oblicz
    field = alpha*0.5*(r**2) - 0.5*(r**2)*math.sin(alpha)
    
    assert(field >= 0)
    return field

def odcinek_field_y(r, yr):
    """
    >>> odcinek_field_y(1.0, 100.0) == math.pi * (1.0**2) * 0.5
    True
    >>> odcinek_field_y(11.11, 100.0) == math.pi * (11.11**2) * 0.5
    True
    """
    if yr >= r:
        return 0.0
    
    xr = math.sqrt(r**2 - yr**2)
    xr,yr = yr,xr
    #print xr, yr
    alpha = math.atan2(yr, xr)
    alpha *= 2.0
    field = alpha*0.5*(r**2) - 0.5*(r**2)*math.sin(alpha)
    assert(field >= 0)
    return field


def circle_part_field(r, xr, yr):
    '''
    zalozenia:
        - prawy gorny rog
        - zero jest w r
        
    >>> circle_part_field(1.0, 0.0, 0.0) == math.pi * (1.0**2) * 0.25
    True
    print circle_part_field(1.0, 0.25, 0.25) + (odcinek_field_x(1.0, 0.0) - odcinek_field_x(1.0, 0.25))*0.5 + (odcinek_field_y(1.0, 0.0) - odcinek_field_y(1.0, 0.25))*0.5 - 0.25*0.25
    print math.pi * (1.0**2) * 0.25
        
    '''
    
    #fx1, fx2 = odcinek_field_x(r, xr), odcinek_field_x(r, xr+w)
    #field_x = (fx1 - fx2)*0.5
    fy1, fy2 = odcinek_field_y(r, 0), odcinek_field_y(r, yr)
    field_y = (fy1 - fy2)*0.5
    field_x = odcinek_field_x(r, xr) * 0.5
    
    field_y -= xr*yr
    field = field_x - field_y
    return field
'''
#print odcinek_field_x(1.0, 0.0)
#print odcinek_field_x(1.0, 0.25)
#print odcinek_field_x(1.0, 0.5)
#print odcinek_field_x(1.0, 0.75)
print odcinek_field_x(1.0, 0.9999)
print odcinek_field_x(1.0, 1.0000)
print odcinek_field_x(1.0, 1.1)
print circle_part_field(1.0, 0.95, 0.50)
print math.pi * (1.0**2) * 0.25
'''
def on_circle(r, p):
    if (p[0]**2)  + (p[1]**2) < (r**2):
        return True
    return False

def generate_points(f, R, t, r, g):
    xm, ym = 0, 0
    n = True
    if g-2*f <= 0.0:
        return
    while True:
        p = (r+f+(g+2*r)*xm, r+f+(g+2*r)*ym, g-2*f, g-2*f)
        if on_circle(R-t-f, p):
            yield p
            ym += 1
            n=False
        else:
            if n:
                break
            xm += 1
            ym=0
            n = True
    return

def count_field(r, p):
    x, y, w, h = p
    p1 = (x,   y)
    p2 = (x,   y+h)
    p3 = (x+w, y+h)
    p4 = (x+w, y)
    
    if on_circle(r, p3):
        return w*h
    
    if on_circle(r, p4) and on_circle(r, p2):
        return circle_part_field(r, x, y) - circle_part_field(r, x+w, y) - circle_part_field(r, x, y+h)
    
    if on_circle(r, p4):
        return circle_part_field(r, x, y) - circle_part_field(r, x+w, y)
    
    if on_circle(r, p2):
        return circle_part_field(r, x, y) - circle_part_field(r, x, y+h)
    
    if on_circle(r, p1):
        return circle_part_field(r, x, y)
    assert False

def count_field_s(r, p):
    x, y, w, h = p
    p1 = (x,   y)
    p2 = (x,   y+h)
    p3 = (x+w, y+h)
    p4 = (x+w, y)
    
    if on_circle(r, p3):
        return "kwadrat"
    
    if on_circle(r, p4):
        return "prawydolnyok"
    
    if on_circle(r, p2):
        return "lewygornyok"
    
    if on_circle(r, p1):
        return "justlewydolny"
    assert False


for case in range(input()):
    '''
    f -> mucha
    R -> promien zew
    t -> R-t -> promien wew
    r -> grubosc polowy sznurka
    g -> wielkosc oka
    '''
    f, R, t, r, g  = map(float, raw_input().split())
    P = list(generate_points(f,R,t,r,g))
    s = [ count_field(R-t-f, p) for p in P ]
    #for i in range(len(s)):
    #    print s[i], P[i], count_field_s(R-t-f, P[i])
    muchafield = 4.0 * sum(s)
    field = (math.pi * (R**2))
    #print muchafield, field
    a= (field-muchafield)/field
    print "Case #%i: %.6f" % (case+1, a)









