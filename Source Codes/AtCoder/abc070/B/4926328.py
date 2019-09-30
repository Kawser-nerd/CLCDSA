a, b, c, d = [int(item) for item in input().split()]

time = 0
for i in range(100):
    if i >= a and i < b and i >= c and i < d:
        time += 1
print(time)