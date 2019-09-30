from decimal import Decimal, ROUND_HALF_UP, ROUND_HALF_EVEN

Deg, Dis = [int(i) for i in input().split()]

Dir = "N"
DegList = [11.25 + 22.5 * i for i in range(16)]
DirList = ["N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"]
DisList = [0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6]

Deg = float(Decimal(str(Deg / 10)).quantize(Decimal('0.1'), rounding=ROUND_HALF_UP))
for i, d in enumerate(DegList):
    if Deg < d:
        Dir = DirList[i]
        break

Dis = float(Decimal(str(Dis / 60)).quantize(Decimal('0.1'), rounding=ROUND_HALF_UP))
W = 12
for i, d in enumerate(DisList):
    if Dis <= d:
        W = i
        if W == 0: Dir = "C"
        break

print(Dir, W)