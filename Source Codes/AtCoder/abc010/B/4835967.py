n = int(input())
flowers = [int(i) for i in input().split()]
petals = 0
for i in flowers:
    if i == 6:
        petals += 3
    elif i == 5:
        petals += 2
    elif i == 8 or i == 4 or i == 2:
        petals += 1
print(petals)