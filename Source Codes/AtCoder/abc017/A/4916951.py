tot = 0
for i in range(3):
    a, b = map(int, input().split())
    tot += a * b*0.1
print(int(tot))