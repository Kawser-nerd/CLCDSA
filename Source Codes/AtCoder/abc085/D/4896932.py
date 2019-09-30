from math import ceil

n, h = map(int, input().split())
ab = [[int(x) for x in input().split()] for y in range(n)]
ab_array = []
for a, b in ab:
    ab_array.append([a, "a"])
    ab_array.append([b, "b"])
ab_array = sorted(ab_array, key=lambda x:x[0], reverse=True)
a_max = ab_array[0][0]


cnt = 0
damage = 0

for value, katana in ab_array:
    if h <= 0:
        print(cnt)
        exit()
    if katana == "a":
        cnt += ceil(h/value)
        break
    else:
        h -= value
        cnt += 1

print(cnt)