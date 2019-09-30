from math import factorial, floor
n = int(input())
a_list = list(map(int, input().split()))

co = a_list.copy()
if 0 in co:
    co.remove(0)
co.sort()


if not len(co) % 2 == 0:
    print(0)
    quit()

for index in range(len(a_list))[:-1:2]:
    if not co[index] == co[index + 1]:
        print(0)
        quit()


print(int(pow(2, floor(n / 2))) % (pow(10,9) + 7))