Deg, Dis = map(int, input().split())
Deg *= 10

if 1125 <= Deg < 3375:
    Dir = "NNE"
elif 3375 <= Deg < 5625:
    Dir = "NE"
elif 5625 <= Deg < 7875:
    Dir = "ENE"
elif 7875 <= Deg < 10125:
    Dir = "E"
elif 10125 <= Deg < 12375:
    Dir = "ESE"
elif 12375 <= Deg < 14625:
    Dir = "SE"
elif 14625 <= Deg < 16875:
    Dir = "SSE"
elif 16875 <= Deg < 19125:
    Dir = "S"
elif 19125 <= Deg < 21375:
    Dir = "SSW"
elif 21375 <= Deg < 23625:
    Dir = "SW"
elif 23625 <= Deg < 25875:
    Dir = "WSW"
elif 25875 <= Deg < 28125:
    Dir = "W"
elif 28125 <= Deg < 30375:
    Dir = "WNW"
elif 30375 <= Deg < 32625:
    Dir = "NW"
elif 32625 <= Deg < 34875:
    Dir = "NNW"
else:
    Dir = "N"

Dis = round(Dis / 60 + 0.01, 1)

if 0.0 <= Dis <= 0.2:
    W = 0
elif 0.3 <= Dis <= 1.5:
    W = 1
elif 1.6 <= Dis <= 3.3:
    W = 2
elif 3.4 <= Dis <= 5.4:
    W = 3
elif 5.5 <= Dis <= 7.9:
    W = 4
elif 8.0 <= Dis <= 10.7:
    W = 5
elif 10.8 <= Dis <= 13.8:
    W = 6
elif 13.9 <= Dis <= 17.1:
    W = 7
elif 17.2 <= Dis <= 20.7:
    W = 8
elif 20.8 <= Dis <= 24.4:
    W = 9
elif 24.5 <= Dis <= 28.4:
    W = 10
elif 28.5 <= Dis <= 32.6:
    W = 11
else:
    W = 12

if W == 0:
    Dir = 'C'

print(Dir, W)