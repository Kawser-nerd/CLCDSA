a = int(input())
b = int(input())
n = int(input())

for i in range(n, 10000000):
    if i == 0:
        continue

    if i % a == 0 and i % b == 0:
        print(i)
        break