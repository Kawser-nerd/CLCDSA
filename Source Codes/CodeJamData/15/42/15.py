t = int(input())

def possible(v, x, rx, t):
    max_vol = []

    for ri, _ in rx:
        max_vol.append(ri * t)

#    print(max_vol)

    if sum(max_vol) < v - 1e-12:
        return False

    min_t = 0
    filled = 0

    for (ri, xi), mv in zip(rx, max_vol):
        taken_vol = min(mv, v - filled)
        filled += taken_vol
        min_t += (taken_vol * xi) / v

#    print("min_t:", min_t)

    if min_t > x + 1e-12:
        return False

    max_t = 0
    filled = 0

    for (ri, xi), mv in reversed(list(zip(rx, max_vol))):
        taken_vol = min(mv, v - filled)
        filled += taken_vol
        max_t += (taken_vol * xi) / v

#    print("max_t:", min_t)

    return not max_t < x - 1e-12

for tc in range(1, t+1):
    n, v, x = map(float, input().split())
    n = int(n)

    rx = []

    for i in range(n):
        ri, ci = map(float, input().split())
        rx.append((1000*ri, ci))

    rx.sort(key=lambda rx: rx[1])
#    print("RX:", rx)

    lo, hi = 0, 1e15

    while hi - lo > 1e-12 and (hi - lo) / hi > 1e-12:
        mid = (hi + lo) / 2

#        print("Trying", mid)

        if possible(v, x, rx, mid):
            hi = mid
        else:
            lo = mid

    if not possible(v, x, rx, hi):
        print("Case #{}: IMPOSSIBLE" .format(tc))
    else:
        print("Case #{}: {:.8f}" .format(tc, 1000*hi))
