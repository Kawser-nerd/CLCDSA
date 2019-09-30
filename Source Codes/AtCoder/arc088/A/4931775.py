x, y = [int(i) for i in input().split(" ")]

i = 0
while x * (2**i) <= y:
    i += 1

print(i)