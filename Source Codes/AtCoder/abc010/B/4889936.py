n = int(input())
a = [int(i) for i in input().split()]
c = 0
for a_ in a:
    if (a_ % 6) == 2:
        c += 1
    elif ((a_ % 6) == 4) | ((a_ % 6) == 5):
        c += (a_ % 6) - 3
    elif (a_ % 6) == 0:
        c += 3
print(c)