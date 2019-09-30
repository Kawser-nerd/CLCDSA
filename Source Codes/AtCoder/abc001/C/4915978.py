a, b = map(int, input().split())

d = ["N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"]

if a < 112.5 or a >= 3487.5:
    a = d[0]
else:
    a = d[int((a + 112.5) / 225)]

w = [0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6]

b /= 60
b += 0.00001

c = int(b * 100)
if c % 10 >= 5:
    c += 10
c //= 10
b = c / 10.0

for i in range(12):
    if b <= w[i]:
        b = i
        break
else:
    b = 12

if b == 0:
    print('C 0')
else:
    print(a, b)