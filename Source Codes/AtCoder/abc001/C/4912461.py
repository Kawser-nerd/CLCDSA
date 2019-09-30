import math
from decimal import Decimal, ROUND_HALF_UP, ROUND_HALF_EVEN
 
Deg, Dis = map(int, input().split())
 
dis = float(Decimal(str(Dis / 60)).quantize(Decimal('0.1'), rounding=ROUND_HALF_UP))
DisList= [0, 0.3, 1.6, 3.4, 5.5, 8, 10.8, 13.9, 17.2, 20.8, 24.5, 28.5, 32.7]
i = 0
while i < len(DisList) - 1:
    if dis >= DisList[i] and dis < DisList[i + 1]:
        W = i
        break
    else:
        i += 1
if i == len(DisList) - 1:
    W = 12
 
DegList = ['N', 'NNE', 'NE', 'ENE', 'E', 'ESE', 'SE', 'SSE', 'S', 'SSW', 'SW', 'WSW', 'W', 'WNW', 'NW', 'NNW']
idx = math.ceil(Deg / 225 - 0.5)
if idx < 16:
    Dir = DegList[idx]
else:
    Dir = DegList[0]
 
if W == 0:
    Dir = 'C'
 
print(Dir, W)