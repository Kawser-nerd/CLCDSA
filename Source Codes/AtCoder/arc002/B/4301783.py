import datetime

day = input()

day_dt = datetime.datetime.strptime(day, '%Y/%m/%d')

while True:
    day_y = int(day_dt.strftime('%Y'))
    day_m = int(day_dt.strftime('%m'))
    day_d = int(day_dt.strftime('%d'))
    ans = day_y % (day_m * day_d)
    
    if ans==0:
        break
    else:
        day_dt += datetime.timedelta(days=1)

print(day_dt.strftime('%Y/%m/%d'))