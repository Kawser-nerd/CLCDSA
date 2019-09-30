n = int(input())
lis = []
for i in range(n - 1):
    lis.append(list(map(int, input().split())))
for j in range(n):
    now = 0
    for i in range(j, n - 1):
        if now < lis[i][1]:
            now += lis[i][1] - now + lis[i][0]
        else:
            if now % lis[i][2] == 0:
                now += lis[i][0]
            else:
                now += lis[i][2] - (now % lis[i][2]) + lis[i][0]
    print(now)