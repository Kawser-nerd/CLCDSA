n = int(input())
a = list(map(int, input().split()))

counter = 0
for i in range(n):
    b = a[i]
    while True:
        if b % 2 == 1:
            break
        b = int(b / 2)
        counter += 1

print(counter)