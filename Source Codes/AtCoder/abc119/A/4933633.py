from datetime import datetime as dt
date = input()
new_date = dt.strptime(date, '%Y/%m/%d')
if new_date <= dt(2019, 4, 30):
  print('Heisei')
else:
  print('TBD')