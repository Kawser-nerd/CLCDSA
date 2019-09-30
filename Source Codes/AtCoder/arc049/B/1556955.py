N = int(input())
norumu_kun = [tuple(map(int, input().split()))for _ in [0]*N]

lb, ub = 0, 10**10
while ub - lb > 1e-5:
    mid = (lb+ub) / 2
    lx = ly = -10**10
    ux = uy = 10**10
    for x, y, c in norumu_kun:
        dist = mid / c
        _lx, _ux = x-dist, x+dist
        _ly, _uy = y-dist, y+dist
        lx = _lx if _lx > lx else lx
        ly = _ly if _ly > ly else ly
        ux = _ux if ux > _ux else ux
        uy = _uy if uy > _uy else uy

    if lx > ux or ly > uy:
        lb = mid
    else:
        ub = mid

print(lb)