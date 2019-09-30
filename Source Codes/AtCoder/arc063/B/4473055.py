n, t = map(int, input().split())
a = list(map(int, input().split()))

# print(a)

minv = a[0]

value = [0] * n
for i, v in enumerate(a[1:], 1):
    if minv >= v:
        value[i] = 0
        minv = v
    else:
        value[i] = v - minv

maxv = max(value)
# print(maxv)
print(value.count(maxv))