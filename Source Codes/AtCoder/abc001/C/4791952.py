a=input().split()
b=0
c=0
if int(a[1])/60<0.25:
    b="C"
elif int(a[0])>=112.5 and int(a[0])<337.5:
    b="NNE"
elif int(a[0])>=337.5 and int(a[0])<562.5:
    b="NE"
elif int(a[0])>=562.5 and int(a[0])<787.5:
    b="ENE"
elif int(a[0])>=787.5 and int(a[0])<1012.5:
    b="E"
elif int(a[0])>=1012.5 and int(a[0])<1237.5:
    b="ESE"
elif int(a[0])>=1237.5 and int(a[0])<1462.5:
    b="SE"
elif int(a[0])>=1462.5 and int(a[0])<1687.5:
    b="SSE"
elif int(a[0])>=1687.5 and int(a[0])<1912.5:
    b="S"
elif int(a[0])>=1912.5 and int(a[0])<2137.5:
    b="SSW"
elif int(a[0])>=2137.5 and int(a[0])<2362.5:
    b="SW"
elif int(a[0])>=2362.5 and int(a[0])<2587.5:
    b="WSW"
elif int(a[0])>=2587.5 and int(a[0])<2812.5:
    b="W"
elif int(a[0])>=2812.5 and int(a[0])<3037.5:
    b="WNW"
elif int(a[0])>=3037.5 and int(a[0])<3262.5:
    b="NW"
elif int(a[0])>=3262.5 and int(a[0])<3487.5:
    b="NNW"
else:
    b="N"
if int(a[1])/60<0.25:
    c=0
elif int(a[1])/60<1.55:
    c=1
elif int(a[1])/60<3.35:
    c=2
elif int(a[1])/60<5.45:
    c=3
elif int(a[1])/60<7.95:
    c=4
elif int(a[1])/60<10.75:
    c=5
elif int(a[1])/60<13.85:
    c=6
elif int(a[1])/60<17.15:
    c=7
elif int(a[1])/60<20.75:
    c=8
elif int(a[1])/60<24.45:
    c=9
elif int(a[1])/60<28.45:
    c=10
elif int(a[1])/60<32.64:
    c=11
else:
    c=12
print(b,c)