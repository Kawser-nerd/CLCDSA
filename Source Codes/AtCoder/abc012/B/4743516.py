from datetime import datetime
from datetime import timedelta

n = int(input())

dt = datetime(1970, 1, 1, 0, 0, 0)
td = timedelta(seconds = n)

dt += td
print(dt.strftime("%H:%M:%S"))