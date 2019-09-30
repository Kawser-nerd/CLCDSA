p = 0.0
for i in range(3):
    l = [int(i) for i in input().split()]
    p += l[0] * l[1] * 0.1
print(int(p))