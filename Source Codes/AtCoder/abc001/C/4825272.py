d, w = map(int,input().split())
deg = "N"
rank = 0

if 112.5 <= d < 337.5:
    deg = "NNE"
elif 337.5 <= d < 562.5:
    deg = "NE"
elif 562.5 <= d < 787.5:
    deg = "ENE"
elif 787.5 <= d < 1012.5:
    deg = "E"
elif 1012.5 <= d < 1237.5:
    deg = "ESE"
elif 1237.5 <= d < 1462.5:
    deg = "SE"
elif 1462.5 <= d < 1687.5:
    deg = "SSE"
elif 1687.5 <= d < 1912.5:
    deg = "S"
elif 1912.5 <= d < 2137.5:
    deg = "SSW"
elif 2137.5 <= d < 2362.5:
    deg = "SW"
elif 2362.5 <= d < 2587.5:
    deg = "WSW"
elif 2587.5 <= d < 2812.5:
    deg = "W"
elif 2812.5 <= d < 3037.5:
    deg = "WNW"
elif 3037.5 <= d < 3262.5:
    deg = "NW"
elif 3262.5 <= d < 3487.5:
    deg = "NNW"

dis = (w+3)//6

if 0 <= dis <= 2:
    rank = 0
    deg = "C"
elif 3 <= dis <= 15:
    rank = 1
elif 16 <= dis <= 33:
    rank = 2
elif 34 <= dis <= 54:
    rank = 3
elif 55 <= dis <= 79:
    rank = 4
elif 80 <= dis <= 107:
    rank = 5
elif 108 <= dis <= 138:
    rank = 6
elif 139 <= dis <= 171:
    rank = 7
elif 172 <= dis <= 207:
    rank = 8
elif 208 <= dis <= 244:
    rank = 9
elif 245 <= dis <= 284:
    rank = 10
elif 285 <= dis <= 326:
    rank = 11
elif 327 <= dis:
    rank = 12

print(deg, rank)