# -*- coding: utf-8 -*-

m = int(input())

vv = 0
if m<100:
    vv = "00"
elif 100<=m<=5000:
    if m <1000:
        vv = "0"+str(int(m/100))
    else:
        vv = int(m/100)
elif 6000<=m<=30000:
    vv = int((m/1000) + 50)
elif 35000<=m<=70000:
    vv = int((((m / 1000)-30)/5)+80)
elif 70000<=m:
    vv = 89

print(vv)