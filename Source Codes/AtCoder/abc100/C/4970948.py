N = int(input())
a = [int(i) for i in input().split()]

count = 0
for i in a:
    j = 2
    while i != 0:
        if i % j == 0:
            count += 1
            i //= 2
        else:
            break

print(count)