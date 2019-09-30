l = list(input())  # ???????
n = int(input())
for i in range(n):
    a, b = map(int, input().split())  # ??????
    tmp = l[a - 1: b - 1]
    del l[a - 1: b - 1]
    tmp = tmp[::-1]
    l[a:a] = tmp

for i in range(len(l)):
    print(l[i], end="")

print("")