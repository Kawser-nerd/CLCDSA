from sys import stdin

A,B = stdin.readline().rstrip().split()
A = int(A)
B = int(B)
count = 0

diff = abs(A-B)

count = 0

while(diff != 0):
    if diff >= 8:
        diff = abs(diff - 10)
    elif diff >= 3:
        diff = abs(diff - 5)
    else:
        diff = diff - 1
    count = count + 1

print(count)