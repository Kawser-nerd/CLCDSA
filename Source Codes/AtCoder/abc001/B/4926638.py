import math

m = int(input())/1000

if m < 0.1:
    print("00")

elif m >= 0.1 and m <= 5:
    if m >= 1.0:
        print(math.floor(m*10))
    else:
        print("0"+str(math.floor(m*10)))

elif m >= 6 and m <= 30:
    print(math.floor(m+50))

elif m >= 35 and m <= 70:
    print(math.floor((m-30)/5+80))

else:
    print(89)