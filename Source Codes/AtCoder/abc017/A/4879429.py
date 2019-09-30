c = 0
for _ in range(3):
    s, e = [int(i) for i in input().split()]
    c += (s * e) * 0.1
print(int(c))