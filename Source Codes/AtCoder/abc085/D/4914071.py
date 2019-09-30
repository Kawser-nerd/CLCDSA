import math

n, h = [int(i) for i in input().split(" ")]
t = []

for i in range(0, n):
    a, b = [int(i) for i in input().split(" ")]
    t.append((a, "a"))
    t.append((b, "b"))

t = sorted(t, key=lambda k: k[0], reverse=True)

c = 0
i = 0

while h > 0:
    if t[i][1] == "b":
        h -= t[i][0]
        c += 1
        i += 1
    else:
        c += math.ceil(h / t[i][0])
        h = 0

print(c)