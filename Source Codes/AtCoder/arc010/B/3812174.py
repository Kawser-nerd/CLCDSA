from datetime import date, timedelta

N = int(input())
MD = [list(map(int, input().split("/"))) for _ in range(N)]

d = date(2012, 1, 1)
overflow_holiday = 0
holiday_count = 0
max_num = 0
for i in range(366):
    if [d.month, d.day] in MD:
        MD.remove([d.month, d.day])
        overflow_holiday += 1
    if d.weekday() in [5, 6]:
        holiday_count += 1
    elif overflow_holiday > 0:
        overflow_holiday -= 1
        holiday_count += 1
    else:
        max_num = max(max_num, holiday_count)
        holiday_count = 0
    d += timedelta(1)
max_num = max(max_num, holiday_count)

print(max_num)