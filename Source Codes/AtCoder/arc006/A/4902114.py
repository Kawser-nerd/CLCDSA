E = [int(i) for i in input().split()]
B = int(input())
L = [int(i) for i in input().split()]
bonus = 0
count = 0
for i in range(6):
    if L[i] in E:
        count += 1
    if L[i] == B:
        bonus = 1
if count == 6:
    print(1)
elif count == 5:
    if bonus == 1:
        print(2)
    else:
        print(3)
elif count == 4:
    print(4)
elif count == 3:
    print(5)
else:
    print(0)