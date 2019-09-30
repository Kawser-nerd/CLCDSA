a, b = map(int, input().split())
dif = b - a
tower_b = 0
for i in range(dif):
    tower_b += i + 1
print(tower_b - b)