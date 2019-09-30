a = list(map(int,input().split(" ")))
b = 0
c = a[3]
for i in range(a[0]):
    k = (c - b) / a[1]
    b = c
    c += k * a[2]
print(c - b)