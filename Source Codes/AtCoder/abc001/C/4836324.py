from decimal import Decimal, ROUND_HALF_UP, ROUND_HALF_EVEN

Deg, Dis = map(int, input().split())

Dir = 'N'
if Deg < 112.5:
  Dir = 'N'
elif Deg < 337.5:
  Dir = 'NNE'
elif Deg < 562.5:
  Dir = 'NE'
elif Deg < 787.5:
  Dir = 'ENE'
elif Deg < 1012.5:
  Dir = 'E'
elif Deg < 1237.5:
  Dir = 'ESE'
elif Deg < 1462.5:
  Dir = 'SE'
elif Deg < 1687.5:
  Dir = 'SSE'
elif Deg < 1912.5:
  Dir = 'S'
elif Deg < 2137.5:
  Dir = 'SSW'
elif Deg < 2362.5:
  Dir = 'SW'
elif Deg < 2587.5:
  Dir = 'WSW'
elif Deg < 2812.5:
  Dir = 'W'
elif Deg < 3037.5:
  Dir = 'WNW'
elif Deg < 3262.5:
  Dir = 'NW'
elif Deg < 3487.5:
  Dir = 'NNW'

W = 0
Fuusoku = float(Decimal(str(Dis / 60)).quantize(Decimal('0.1'), rounding=ROUND_HALF_UP))
#print(Fuusoku)
if Fuusoku <= 0.2:
  W = 0
elif Fuusoku <= 1.5:
  W = 1
elif Fuusoku <= 3.3:
  W = 2
elif Fuusoku <= 5.4:
  W = 3
elif Fuusoku <= 7.9:
  W = 4
elif Fuusoku <= 10.7:
  W = 5
elif Fuusoku <= 13.8:
  W = 6
elif Fuusoku <= 17.1:
  W = 7
elif Fuusoku <= 20.7:
  W = 8
elif Fuusoku <= 24.4:
  W = 9
elif Fuusoku <= 28.4:
  W = 10
elif Fuusoku <= 32.6:
  W = 11
else:
  W = 12

if W == 0:
  Dir = 'C'
  
print("{0} {1}".format(Dir, W))