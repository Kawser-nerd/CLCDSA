y, m, d = map(int, input().split('/'))

def leap_year(y):
    if y % 400 == 0:
        return True
    if y % 100 == 0:
        return False
    if y % 4 == 0:
        return True
    return False

lims = {1: 31, 2: 28, 3: 31, 4: 30, 5: 31, 6: 30, 7: 31, 8: 31, 9: 30, 10: 31, 11: 30, 12: 31}

while m <= 12:
    lim = lims[m]
    if leap_year(y) and m == 2:
        lim += 1
    while d <= lim:
        if y % (m * d) == 0:
            print("{year:02d}/{month:02d}/{date:02d}".format(year=y, month=m, date=d))
            exit()
        d += 1
    d = 1
    m += 1
print("{year:02d}/{month:02d}/{date:02d}".format(year=y+1, month=1, date=1))