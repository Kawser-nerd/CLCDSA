Deg,Dis = map(int,input().split())

if 112.5<=Deg<337.5:
    Dir = "NNE"
elif 337.5<=Deg<562.5:
    Dir = "NE"
elif 562.5<=Deg<787.5:
    Dir = "ENE"
elif 787.5<=Deg<1012.5:
    Dir = "E"
elif 1012.5<=Deg<1237.5:
    Dir = "ESE"
elif 1237.5<=Deg<1462.5:
    Dir = "SE"
elif 1462.5<=Deg<1687.5:
    Dir = "SSE"
elif 1687.5<=Deg<1912.5:
    Dir = "S"
elif 1912.5<=Deg<2137.5:
    Dir = "SSW"
elif 2137.5<=Deg<2362.5:
    Dir = "SW"
elif 2362.5<=Deg<2587.5:
    Dir = "WSW"
elif 2587.5<=Deg<2812.5:
    Dir = "W"
elif 2812.5<=Deg<3037.5:
    Dir = "WNW"
elif 3037.5<=Deg<3262.5:
    Dir = "NW"
elif 3262.5<=Deg<3487.5:
    Dir = "NNW"
else:
    Dir = "N"
    
if 0<=Dis<15:
    W = "0"
    Dir = "C"
elif 15<=Dis<93:
    W = "1"
elif 93<=Dis<201:
    W = "2"
elif 201<=Dis<327:
    W = "3"
elif 327<=Dis<477:
    W = "4"
elif 477<=Dis<645:
    W = "5"
elif 645<=Dis<831:
    W = "6"
elif 831<=Dis<1029:
    W = "7"
elif 1029<=Dis<1245:
    W = "8"
elif 1245<=Dis<1467:
    W = "9"
elif 1467<=Dis<1707:
    W = "10"
elif 1707<=Dis<1959:
    W = "11"
else:
    W = "12"

print(Dir,W)