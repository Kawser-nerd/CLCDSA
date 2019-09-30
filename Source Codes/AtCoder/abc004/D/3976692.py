from math import *

R, G, B = [int(x) for x in input().strip().split()]
pr = -100
pg = 0
pb = 100
R0min = min(floor(-(R-1)/2) + pr, floor(-(B-1)/2) - G - R)
R0max = ceil(-(R-1)/2) + pr
B0min = floor(-(B-1)/2) + pb
B0max = max(ceil(-(B-1)/2) + pb, ceil((R-1)/2) + G)

def sumn(n):
    return int(n*(n+1)/2)

def calc_count(n, p0, p1, c):
    if p0 <= c and p1 >= c:
        return sumn(abs(p0-c)) + sumn(abs(p1-c))
    elif p0 > c:
        return (p0-c) * n + sumn(n-1)
    else:
        return (c-p1) * n + sumn(n-1)

minmove = 2**31

for r0 in range(R0min, R0max+1):
    for b0 in range(B0min, B0max+1):
        r1 = r0 + R - 1
        b1 = b0 + B - 1
        if G >= b0 - r1:
            continue
        if -(r1 + 1) <= b0 - 1:
            g0 = max(floor(-(G-1)/2), r1 + 1)
            g1 = g0 + G - 1
        else:
            g1 = min(ceil((G-1)/2), b0-1)
            g0 = g1 - G + 1
        count = 0
        count += calc_count(R, r0, r1, pr)
        count += calc_count(G, g0, g1, pg)
        count += calc_count(B, b0, b1, pb)
        if count <= minmove:
            minmove = count

print(minmove)