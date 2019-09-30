a = int(input())
b = int(input())
up_count = 0
down_count = 0
a1 = a
a2 = a
while (a1 != b):
    if (a1 == 9):
        a1 = 0
        up_count += 1
    else:
        a1 += 1
        up_count += 1
while (a2 != b):
    if (a2 == 0):
        a2 = 9
        down_count += 1
    else:
        a2 -= 1
        down_count += 1
print(min(up_count, down_count))