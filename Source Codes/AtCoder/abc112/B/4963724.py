n, t = map(int, input().split())
ct = []
for i in range(n):
    ct.append(list(map(int, input().split())))
num = 1001
has_tle = False

for i in range(n):
    if t >= ct[i][1]:
        if num >= ct[i][0]:
            num = ct[i][0]
        has_tle = True

if has_tle == True:
    print(num)
else:
    print('TLE')