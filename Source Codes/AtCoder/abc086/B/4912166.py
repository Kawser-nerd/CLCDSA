a, b = input().split()
n = int(a + b)
m = n ** 0.5
i = int(m)
f = m - int(m)
if f == 0:
    print('Yes')
else:
    print('No')