import sys

N = int(input())
A = [int(x) for x in input().split()]

n4 = 0
n2 = 0
n1 = 0
for a in A:
    if a % 4 == 0:
        n4 += 1
    elif a % 2 == 0:
        n2 += 1
    else:
        n1 += 1

type = 4

for i in range(N):
    if type == 4:
        if n1 > 0:
            n1 -= 1
            type = 1
        elif n2 > 0:
            n2 -= 1
            type = 2
        elif n4 > 0:
            n4 -= 1
            type = 4
    elif type == 2:
        if n2 > 0:
            n2 -= 1
            type = 2
        elif n4 > 0:
            n4 -= 1
            type = 4
        else:
            print("No")
            sys.exit(0)
    else:
        if n4 > 0:
            n4 -= 1
            type = 4
        else:
            print("No")
            sys.exit(0)

print("Yes")