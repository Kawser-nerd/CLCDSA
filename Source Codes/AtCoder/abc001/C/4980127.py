a = list(map(int, input().split()))


if a[1] < 15:
    res1 = "0"
elif a[1] < 93:
    res1 = "1"
elif a[1] < 201:
    res1 = "2"
elif a[1] < 327:
    res1 = "3"
elif a[1] < 477:
    res1 = "4"
elif a[1] < 645:
    res1 = "5"
elif a[1] < 831:
    res1 = "6"
elif a[1] < 1029:
    res1 = "7"
elif a[1] < 1245:
    res1 = "8"
elif a[1] < 1467:
    res1 = "9"
elif a[1] < 1707:
    res1 = "10"
elif a[1] < 1959:
    res1 = "11"
else:
    res1 = "12"


if res1 == "0":
    res0 ="C"
elif a[0] >= 1687.5 and a[0] < 1912.5:
    res0 ="S"
elif a[0] >= 112.5 and a[0] < 337.5:
    res0 ="NNE"
elif a[0] >= 1912.5 and a[0] < 2137.5:
    res0 ="SSW"
elif a[0] >= 337.5 and a[0] < 562.5:
    res0 ="NE"
elif a[0] >= 2137.5 and a[0] < 2362.5:
    res0 ="SW"
elif a[0] >= 562.5 and a[0] < 787.5:
    res0 ="ENE"
elif a[0] >= 2362.5 and a[0] < 2587.5:
    res0 ="WSW"
elif a[0] >= 787.5 and a[0] < 1012.5:
    res0 ="E"
elif a[0] >= 2587.5 and a[0] < 2812.5:
    res0 ="W"
elif a[0] >= 1012.5 and a[0] < 1237.5:
    res0 ="ESE"
elif a[0] >= 2812.5 and a[0] < 3037.5:
    res0 ="WNW"
elif a[0] >= 1237.5 and a[0] < 1462.5:
    res0 ="SE"
elif a[0] >= 3037.5 and a[0] < 3262.5:
    res0 ="NW"
elif a[0] >= 1462.5 and a[0] < 1687.5:
    res0 ="SSE"
elif a[0] >= 3262.5 and a[0] < 3487.5:
    res0 ="NNW"
else:
    res0 ="N"



print(res0+" "+res1)