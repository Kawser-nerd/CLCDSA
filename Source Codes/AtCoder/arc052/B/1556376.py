from math import pi
N, Q = map(int, input().split())
a = sorted([(a,a+h,r,h) for _ in [0]*N for a, r, h in ((map(int, input().split()),))]) + [(10**9, 10**9, 1, 1)]
result = []
append = result.append
for _ in [0]*Q:
    qx1, qx2 = map(int, input().split())
    total = 0
    i = 0
    x1, x2, r, h = a[i]
    while x1 < qx2:
        if x2 > qx1:
            lx, ux = x1 if x1 > qx1 else qx1, qx2 if x2 > qx2 else x2
            rh = x2 - lx
            #print(x1, x2, h)
            total += (r*(rh/h))**2*pi*rh/3
            if x2 > qx2:
                _h = x2-qx2
                total -= (r*(_h/h))**2*pi*_h/3
        i += 1
        x1, x2, r, h = a[i]
    append(total)

print("\n".join(map(str, result)))