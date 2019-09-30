import datetime
sec = int(input())
dt = datetime.timedelta(seconds = sec)
if dt < datetime.timedelta(hours = 10):
    print("0",dt,sep='')
else:
    print(dt)