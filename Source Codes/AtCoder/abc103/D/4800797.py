import numpy as np
N, M  = map(int,input().split())
ab = [list(map(int,input().split())) for _ in range(M)]
ab.sort(key=lambda student: student[1])
temp = [0,0]
count = 0
for x in ab:
    if  x[0] <= temp[0] and temp[1] <= x[1] :
        continue
    else:
        temp[0] = x[1]-1
        temp[1] = x[1]
        count += 1
print(count)