n = int(input())
a = map(int, input().rstrip().split())

count = 0
for i in a:
    if i % 6 == 0:
        count += 3
    elif i % 6 == 5:
        count += 2
    elif i % 2 == 0:
        count += 1

print(count)