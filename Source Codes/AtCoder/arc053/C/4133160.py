n = int(input())
a = [0 for i in range(n)]
b = [0 for i in range(n)]
for i in range(n):
    a[i], b[i] = map(int, input().split())

c = [(a[i] - b[i]) for i in range(n)]
d = [[a[i], b[i], c[i]] for i in range(n)]

d.sort(key=lambda x: x[2])
d1 = list(filter(lambda x: x[2] < 0, d))
d2 = list(filter(lambda x: x[2] >= 0, d))

d1.sort(key=lambda x: x[0])
d2.sort(key=lambda x: x[1], reverse=True)

max = 0
temp = 0
for i in range(len(d1)):
    temp += d1[i][0]
    if temp > max:
        max = temp
    temp -= d1[i][1]

for i in range(len(d2)):
    temp += d2[i][0]
    if temp > max:
        max = temp
    temp -= d2[i][1]

print(max)