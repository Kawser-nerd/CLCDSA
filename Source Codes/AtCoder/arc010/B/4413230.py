# ??????
days = [False] * 1000

for i in range(1000):
    if i % 7 == 0 or i % 7 == 6:
        days[i] = True

def conv(m, d):
    month = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    ret = 0
    for i in range(m - 1):
        ret += month[i]
    return ret + d

n = int(input())
for i in range(n):
    m, d = map(int,input().split('/'))
    c = conv(m, d) - 1
    while days[c] == True:
        c += 1
    days[c] = True

res = 2
cnt = 0
for i in range(366):
    if days[i]:
        cnt += 1
    else:
        res = max(res, cnt)
        cnt = 0
else:
    res = max(res, cnt)

print(res)
# print(days)