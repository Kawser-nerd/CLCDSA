n = input()


if len(n) == 1:
    print(int(n))
    exit()
flag = 0
for i in range(len(n)):
    if int(n[i]) != 9:
        flag = 1
if flag == 0:
    print(9 * len(n))
    exit()

flag = 0
for i in range(1, len(n)):
    if int(n[i]) != 9:
        flag = 1

if flag == 0:
    print(int(n[0]) + 9 * (len(n)-1))
    exit()

print(int(n[0]) - 1 + 9 * (len(n) - 1))