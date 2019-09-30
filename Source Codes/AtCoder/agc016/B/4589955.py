n = int(input())
a = list(map(int, input().split()))

ma = max(a)
for ai in a:
    if ai < ma - 1:
        print("No")
        exit()

flag = 0
for ai in a:
    if ai == ma - 1:
        flag = 1

# ???????????
if flag:
    count = 0
    for ai in a:
        if ai == ma - 1:
            count += 1
    if (n - count) == 1:
        print("No")
        exit()
    count_min = count + 1
    count_max = count + (n - count) // 2
    if (count_min <= ma) and (ma <= count_max):
        print("Yes")
        exit()
    else:
        print("No")
        exit()

# ???????
if ma == n-1:
    print("Yes")
    exit()
if (1 <= ma) and (ma <= n // 2):
    print("Yes")
    exit()
print("No")