y,m,d = map(int,input().split('/'))
month = [-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def next_date(y,m,d):
    d += 1
    if month[m] < d:
        m += 1
        d = 1
    if m > 12:
        y += 1
        m %= 12
    return (y,m,d)

def leap_year(year):
    if year % 400 == 0:
        return True
    if year % 100 == 0:
        return False
    return year % 4 == 0

if leap_year(y):
    month[2] += 1

while 1:
    s = str(y) + '%(' + str(m) + '*' + str(d) + ')'
    if eval(s) == 0:
        break
    y,m,d = next_date(y,m,d)

print('{0:04d}/{1:02d}/{2:02d}'.format(y, m, d))