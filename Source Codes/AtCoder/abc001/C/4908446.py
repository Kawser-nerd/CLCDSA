deg, dis = map(int, input().split())
deg = deg * 10

jdegs = [1125 + j * (36000//16) for j in range(17)]
jdcts = ["N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
        "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"]
    
for jdeg, jdct in zip(jdegs, jdcts):
    if deg < jdeg:
        dct = jdct
        break

jpows = [0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6]

def round(x, d=0):
    p = 10**d
    return (x * p * 2 + 1) // 2 / p

spd = round(dis / 60, 1)
power = 12
for i, jpow in enumerate(jpows):
    if spd <= jpow:
        power = i
        break

if power == 0:
    dct = "C"

print(dct, power)