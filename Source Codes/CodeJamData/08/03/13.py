#! /opt/local/bin/python
# -*- coding: utf8 -*-

from math import sqrt, pi, sin, asin

def pillar_area(radius, from_val, to_val):
    area = 0.0
    start_rad = asin(from_val /radius)
    end_rad   = asin(to_val   /radius)

    area += ( end_rad   + sin(end_rad  *2) / 2 )
    area -= ( start_rad + sin(start_rad*2) / 2 )

    area *= ( radius**2 / 2 )

    return area

def check_gap(x, y, gap, sq_rad ):
    area = 0.0
    r1 = x**2 + y**2
    if r1 > sq_rad:
        return [ 0, 0.0 ] # Complete OUT

    r4 = (x+gap)**2 + (y+gap)**2
    if r4 <= sq_rad:
        return [ 1, 0.0 ] # Complete IN

    r2 = (x+gap)**2 + y**2
    r3 = x**2 + (y+gap)**2

    if r2 > sq_rad:
        if r3 > sq_rad:
            area += pillar_area(sqrt(sq_rad), x, sqrt(sq_rad - y**2 ))
            area -= y * ( sqrt(sq_rad - y**2) - x )
            return [ 2, area ]
        else:
            area += pillar_area(sqrt(sq_rad), y, y+gap)
            area -= x * gap
    else:
        if r3 > sq_rad:
            area += pillar_area(sqrt(sq_rad), x, x+gap)
            area -= y * gap
            return [ 2, area ]
        else:
            area += pillar_area(sqrt(sq_rad), x, x+gap)
            area -= y * gap
            tmp   = pillar_area(sqrt(sq_rad), x, sqrt(sq_rad - (y+gap)**2 ))
            tmp  -= (y+gap) * ( sqrt(sq_rad - (y+gap)**2) - x )
            area -= tmp
            return [ 2, area ]

def main():
    for c in range(input()):
        f, radius, t, r, g = map(float,raw_input().split())
        probability = 0.0

        t += f
        g -= 2*f
        r += f
        sq_radius = radius**2

        if g <= 0.0:
            probability = 1.0
        else:
            sq_area = g * g
            cycle = g + 2*r
            sq_count = 0
            area_total = 0.0
            in_radius = radius - t
            sq_in_radius = in_radius**2

            size = int(radius // cycle)
            area = [[-1.0] * ( size+1 ) for i in range(size+1)]
            
            for i in range(size+1):
                for j in range(size+1):
                    if area[i][j] < 0.0:
                        state, val = check_gap( i*cycle + r, j*cycle + r, g, sq_in_radius)
                        if state == 0:
                            pass
                        elif state == 1:
                            sq_count += 1
                            area[i][j] = 0.0
                        elif state == 2:
                            area[i][j] = val
                            area[j][i] = val

            for i in area:
                for j in i:
                    if j > 0.0:
                        area_total += j

            area_total += sq_count*sq_area

            probability = 1.0 - ( area_total / ( pi * sq_radius / 4 ) )

        print 'Case #%d: %.6f'% ( c+1, probability  )

if __name__ == '__main__':
    main()

