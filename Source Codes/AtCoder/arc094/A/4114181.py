temp = list(map(int, input().split()))
temp.sort()
a, b, c = temp[0], temp[1], temp[2]
count = 0

while(c - b > 1):
    b += 2
    count += 1

while(b - a > 1):
    a += 2
    count += 1

if a == b == c: print(count)
elif c - b == 1 and b - a == 1: print(count + 3)
elif c - b == 1 and b - a == 0: print(count + 1)
else: print(count + 2)