import re
import math

def circle_integral(x, R):
    return ((x*math.sqrt(R**2 - x**2)/2) + ((R**2)/2)*math.asin(x/R))


def wedge_integral(x,y,R):
    if math.sqrt(x**2 + y**2) >= R:
        return 0.0

    xa = math.sqrt(R**2 - y**2)
    area = circle_integral(xa,R) - circle_integral(x,R) - y*(xa - x)
    return area

def area_within(x0, y0, x1, y1, x2, y2, x3, y3, R):
    r0 = math.sqrt(x0**2 + y0**2)
    r1 = math.sqrt(x1**2 + y1**2)
    r2 = math.sqrt(x2**2 + y2**2)
    r3 = math.sqrt(x3**2 + y3**2)

    if r0 > R:
        return 0.0

    if r2 <= R:
        return (x1 - x0)*(y3 - y0)

    area = wedge_integral(x0, y0, R) \
           - wedge_integral(x1, y1, R) \
           - wedge_integral(x3, y3, R) \
           + wedge_integral(x2, y2, R)

    return area


##fin = open('C-test.in', 'r')
fin = open('C-large.in', 'r')

N_cases = int(re.match('\d+', fin.readline()).group(0))

for case in range(N_cases):
    aux = re.findall('[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?', fin.readline())
    aux = [float(x) for x in aux]
    f = aux[0]
    R = aux[1]
    t = aux[2]
    r = aux[3]
    g = aux[4]

    if 2*f >= g:
        # Fat flies: p = 1.0
        print 'Case #%d: ' % (case + 1) + '1.000000'
        continue

    # Skinny flies: p < 1.0
    N_squares = int(math.ceil((R - t - f)/(g + 2*r)))

    total_area = 0.0
    for sq_r in range(N_squares):
        for sq_c in range(N_squares):
            # lower corner
            lx = float(sq_r)*(g + 2*r)
            ly = float(sq_c)*(g + 2*r)

            x0 = lx + r + f
            x1 = lx + r + g - f
            x2 = x1
            x3 = x0

            y0 = ly + r + f
            y1 = y0
            y2 = ly + r + g - f
            y3 = y2

            total_area += area_within(x0, y0, x1, y1, x2, y2, x3, y3, R - t - f)

    p = 1.0 - total_area/((math.pi*(R**2))/4)

    print 'Case #%d: ' % (case + 1) + '%.6f' % p


fin.close()