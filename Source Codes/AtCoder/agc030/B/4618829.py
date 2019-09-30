ln, kn, *ki = map(int, open(0).read().split())
# ???
pa = ki[-1]
ky = [pa]
kigu = 1
for ys in range(2, kn + 1):
    # ?????????
    if kigu == 1:
        pa += ki[kn - ys] * 2 + ln - ki[-(ys // 2)] * 2
    # ?????????
    else:
        pa += ki[kn - ys] * 2 - ki[-(ys // 2) - 1] + ln - ki[-(ys // 2)]
    ky.append(pa)
    kigu *= -1

# ???
pa = ln - ki[0]
ky.append(pa)
kigu = 1
for ys in range(2, kn + 1):
    # ?????????
    if kigu == 1:
        pa += (ln-ki[ys - 1]) * 2 - ln + ki[ys // 2 - 1] * 2
    # ?????????
    else:
        pa += (ln-ki[ys - 1]) * 2+ki[ys//2]-ln+ki[ys//2-1]
    ky.append(pa)
    kigu *= -1

print(max(ky))