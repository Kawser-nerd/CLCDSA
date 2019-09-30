N = int(input())
a = list(map(int, input().split()))
d2 = 0
d4 = 0
for i in a:
    if i % 4 == 0:
        d4 += 1
    elif i % 2 == 0:
        d2 += 1
if d4 >= N // 2:
    print("Yes")
elif d2 >= N - d4 * 2:
    print("Yes")
else:
    print("No")