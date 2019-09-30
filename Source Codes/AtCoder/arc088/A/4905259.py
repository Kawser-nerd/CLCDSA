X, Y = map(int, input().split())

count = 0
while X <= Y:
    count += 1
    X *= 2

print(count)