n = int(input())
s = [input() for _ in range(n)]

d = 24 * 60 + 1

t = [0] * d

for x in s:
    a = int(x[:4])
    b = int(x[5:])
    if a % 10 < 5:
        a -= a % 10
    elif 5 < a % 10:
        a -= a % 10 - 5
    if 0 < b % 10 < 5:
        b += 5 - b % 10
    elif b % 10 > 5:
        b += 10 - b % 10
    a = (a // 100) * 60 + a % 100
    b = (b // 100) * 60 + b % 100
    #print(a, b)
    t[a] += 1
    t[b] -= 1

for i in range(1, d):
    t[i] += t[i-1]

a = 0
while a < d:
    while a < d:
        if t[a] > 0:
            break
        else:
            a += 1
    else:
        break
    b = a
    while b < d:
        if t[b] == 0:
            break
        else:
            b += 1
    x = (a // 60) * 100 + a % 60 + 10000
    y = (b // 60) * 100 + b % 60 + 10000
    x = list(str(x))
    y = list(str(y))
    print(''.join(x[1:]) + '-' + ''.join(y[1:]))
    a = b + 1