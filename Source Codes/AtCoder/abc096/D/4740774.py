n = int(input())

import math
import itertools
sosu = [0]*2 + [1]*(10**5)

for i, item in enumerate(sosu):
  if i > math.sqrt(len(sosu)):
    break
  if item:
    for j in range(2, len(sosu)//i):
      sosu[j*i] = 0

sosu_num = []
for i in range(len(sosu)):
  if sosu[i] and i % 5 == 1:
    sosu_num.append(i)

ans = sosu_num[:n]
for item in ans:
  print(item, end=" ")