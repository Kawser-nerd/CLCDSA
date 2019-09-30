n = int(input())
a = [int(input()) for _ in range(n)]

count = 0
i = 0
while count <= 10e+5:
    count += 1
    if a[i] == 2:
        print(count)
        break
    else:
        i = a[i]-1
else:
    print(-1)