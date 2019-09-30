temp = list(map(int, input().split()))
temp.sort()
a, b, c = temp[0], temp[1], temp[2]

if (2 * c - a - b) % 2 == 0:
    print((2 * c - a - b) // 2)
else:
    print((2 * c - a - b + 3) // 2)