n = int(input())
a = set(map(int, input().split()))

b = set()

for x in a:
    while x % 2 == 0:
        x //= 2
    b.add(x)

print(len(b))