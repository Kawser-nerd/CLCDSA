m = float(input()) / 1000


if m < 0.1:
  vv = 0
elif m <= 5 :
  vv = m * 10
elif m <= 30 :
  vv = m + 50
elif 35 <= m and m <= 70 :
  vv = (m - 30) / 5 + 80
elif 70 <= m :
  vv = 89
  
if vv < 10:
  print("0" + str(int(vv)))
else:
  print(int(vv))