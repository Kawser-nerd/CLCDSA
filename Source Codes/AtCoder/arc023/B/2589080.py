import numpy as np
r, c, d = map(int, input().split())
a_list = []
for i in range(r):
    a = list(map(int, input().split()))
    a_list.append(a)
if d%2 == 0:
    a_max = a_list[0][0]
else:
    a_max = max(a_list[0][1], a_list[1][0])
for i in range(r):
    if i > d:
        break
    for j in range(c):
        if i+j > d:
            break
        elif (i+j)%2 == d%2:
            a_max = max(a_max, a_list[i][j])

print(a_max)