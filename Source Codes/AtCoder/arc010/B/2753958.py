d_num = [0,31,29,31,30,31,30,31,31,30,31,30,31]
D = 366
def days(m, d):
    for i in range(m):
        d += d_num[i]
    return d-1

holiday = [0]*D
for i in range(D):
    if i%7 == 0 or i%7 == 6:
        holiday[i] += 1

n = int(input())
for _ in range(n):
    m, d = map(int, input().split('/'))
    d = days(m, d)
    holiday[d] += 1

c = 0
for i in range(D):
    if holiday[i] > 0:
        c += holiday[i]-1
    elif c > 0:
        holiday[i] += 1
        c -= 1

ans = 0
s = 0
for i in range(D):
    if holiday[i] > 0:
        s += 1
        ans = max(ans, s)
    else:
        s = 0
print(ans)