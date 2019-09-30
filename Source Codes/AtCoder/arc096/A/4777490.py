a, b, c, x, y = map(int, input().split())
min_val = 2**30
if x < y:
    tmp = x
    x = y
    y = tmp
    tmp = a
    a = b
    b = tmp

for i in range(x + 1):
    k = (x - i) * 2
    k = 0 if k < 0 else k
    j = y - (k // 2)
    j = 0 if j < 0 else j
    val = i * a + j * b + k * c
    if val < min_val:
        min_val = val
print(min_val)