import datetime
y, m, d = list(map(int, input().split("/")))
t = datetime.date(y, m, d)
while True:
  y, m, d = t.year, t.month, t.day
  if y/m/d%1==0:
    print("{0}/{1:02}/{2:02}".format(y, m, d))
    break
  t = t+datetime.timedelta(days=1)