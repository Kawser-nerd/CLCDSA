from datetime import date, timedelta

Y, M, D = map(int, input().split('/'))

dt = date(Y, M, D)
ddt = timedelta(days=1)

while True:
    y = dt.year
    m = dt.month
    d = dt.day
    if y % (m*d) == 0:
        print(dt.strftime('%Y/%m/%d'))
        break
    dt += ddt