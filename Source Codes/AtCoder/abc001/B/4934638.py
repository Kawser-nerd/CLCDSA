while True:
    m = int(input())
    if m >= 0:
        if m <= 100000:
            break

if m < 100:
    vv = 0
elif m <= 5000:
    vv = m // 100
elif 6000 <= m <= 30000:
    vv = m // 1000 + 50
elif 35000 <= m <= 70000:
    vv = (m // 1000 -30) // 5 + 80
else:
    vv = 89

print('{:02d}'.format(vv))