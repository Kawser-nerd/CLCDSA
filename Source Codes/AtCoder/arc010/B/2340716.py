from datetime import datetime, timedelta

N = int(input())

hol = [(i+1)%7 < 2 for i in range(366)]
epoch = datetime(2012, 1, 1)
for i in range(N):
    m, d = map(int, input().split('/'))
    cur = datetime(2012, m, d)
    days = (cur-epoch).days
    for j in range(days, 366):
        if hol[j]:
            continue
        hol[j] = True
        break

hol = ''.join(['01'[i] for i in hol])
print(max(map(len, hol.split('0'))))