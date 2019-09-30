from datetime import datetime


N = int(input())
flag = [True if i % 7 == 0 or i % 7 == 6 else False for i in range(366)]
start = datetime(year=2012, month=1, day=1)
for _ in range(N):
    month, day = map(int, input().split('/'))
    index = (datetime(year=2012, month=month, day=day) - start).days
    while True:
        if index < 366:
            if flag[index]:
                index += 1
            else:
                flag[index] = True
                break
        else:
            break

ans = 0
length = 0
for i in range(366):
    if flag[i]:
        length += 1
        ans = max(ans, length)
    else:
        length = 0

print(ans)