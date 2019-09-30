m = int(input())
vv = '00'

if 100 <= m <= 900:
    vv = '0' + str(int(m / 100))
elif 1000 <= m <= 5000:
    vv = str(int(m / 100))
elif 6000 <= m <= 30000:
    vv = str(int(m / 1000 + 50))
elif 35000 <= m <= 70000:
    vv = str(int((m / 1000 - 30) / 5 + 80))
elif m >= 70000:
    vv = '89'

print(vv)