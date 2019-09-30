import math

n, m = map(int, input().split())
max_i = 1
for i in range(1, int(math.sqrt(m)) + 1):
    if m % i != 0:
        continue
    j = m // i
    if i * n <= m and i > max_i:
        max_i = i
    if j * n <= m and j > max_i:
        max_i = j
print(max_i)