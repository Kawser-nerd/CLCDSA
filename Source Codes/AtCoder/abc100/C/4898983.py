N = int(input())
an = list(map(int, input().split()))

count = 0
for a in an:
    while a % 2 == 0:
        count += 1
        a = a // 2
print(count)