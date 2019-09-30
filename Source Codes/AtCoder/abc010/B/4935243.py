N = int(input())
A = [int(i) for i in input().split()]

res = 0

for i in A:
    if i == 2 or i == 4 or i == 8:
        res += 1
    elif i == 5:
        res += 2
    elif i == 6:
        res += 3

print(res)