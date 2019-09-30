N = int(input())

for i in range(100000):
    if i * i > N:
        break
print((i - 1) * (i - 1))