N = int(input())
A = list(map(int, input().split(' ')))
c = 0
for a in A:
    while True:
        if a % 2 != 0 and a % 3 != 2:
            break
        a -= 1
        c += 1
print(c)