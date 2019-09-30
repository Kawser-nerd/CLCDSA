a = int(input())
a = a / 1000

if a < 0.1:
    v = 00
elif a >= 0.1 and a <= 5:
    v = a * 10
elif a >= 6 and a <= 30:
    v = a + 50
elif a >= 35 and a <= 70:
    v = (a - 30)/5 + 80
elif a > 70:
    v = 89
else:
    print('error')

print(format(round(v), '02'))