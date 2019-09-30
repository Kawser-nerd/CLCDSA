from datetime import datetime, timedelta

DATE_FORMAT = "%Y/%m/%d"

date = datetime.strptime(input(), DATE_FORMAT)

while date.year % (date.month * date.day) != 0:
    date += timedelta(days=1)

print(date.strftime(DATE_FORMAT))