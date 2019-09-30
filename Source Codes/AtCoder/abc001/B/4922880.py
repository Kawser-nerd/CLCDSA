range=int(input())

if range <= 5000:
  print("{:02d}".format(range // 100 ))
elif range <= 30000:
  print("{:02d}".format(range // 1000 + 50))
elif range <= 70000:
  print("{:02d}".format( (range // 1000 - 30)//5 + 80 ))
else:
  print(89)