from collections import Counter

s = list(input())
t = int(input())

c = Counter(s)

if t == 1:
    print(abs(c['U'] - c['D']) + abs(c['L'] - c['R']) + c['?'])
else:
    temp = abs(c['U'] - c['D']) + abs(c['L'] - c['R'])
    if temp >= c['?']:
        print(temp - c['?'])
    else:
        print(abs(temp - c['?']) % 2)